/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:39:41 by kwillian          #+#    #+#             */
/*   Updated: 2025/07/25 01:39:27 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	exec_clean(t_shell *shell)
{
	shell->mistake = 0;
	shell->mistake2 = 0;
	shell->exit_code = 0;
	execute_all_cmds(shell);
	close_redirections(shell->cmd);
	free_token_list(shell);
	free_cmds(shell->cmd);
	shell->cmd = NULL;
}

int	run(t_shell *shell)
{
	char	*input;

	while (1)
	{
		shell->mistake = 0;
		g_heredoc_interrupted = 0;
		check_cwd();
		signal_search(ROOT);
		input = readline("minishell: ");
		if (!input)
			get_out(shell);
		if (input[0] == '\0')
		{
			free(input);
			continue ;
		}
		validator(input, shell);
		free(input);
	}
	return (1);
}

static int	get_shlvl_index(t_shell *shell, int *current_lvl)
{
	int	i;

	i = 0;
	*current_lvl = 0;
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], "SHLVL=", 6) == 0)
		{
			*current_lvl = ft_atoi(shell->env[i] + 6);
			return (i);
		}
		i++;
	}
	return (-1);
}

void	update_shlvl_helper(t_shell *shell, int i, char *new_lvl)
{
	char	**tmp;

	if (i >= 0)
	{
		free(shell->env[i]);
		shell->env[i] = new_lvl;
	}
	else
	{
		i = 0;
		while (shell->env[i])
			i++;
		tmp = realloc(shell->env, sizeof(char *) * (i + 2));
		if (!tmp)
		{
			free(new_lvl);
			return ;
		}
		shell->env = tmp;
		shell->env[i] = new_lvl;
		shell->env[i + 1] = NULL;
	}
}

void	update_shlvl(t_shell *shell)
{
	int		i;
	int		current_lvl;
	char	*lvl_str;
	char	*new_lvl;

	i = get_shlvl_index(shell, &current_lvl);
	current_lvl++;
	lvl_str = ft_itoa(current_lvl);
	if (!lvl_str)
		return ;
	new_lvl = ft_strjoin("SHLVL=", lvl_str);
	free(lvl_str);
	if (!new_lvl)
		return ;
	update_shlvl_helper(shell, i, new_lvl);
}
