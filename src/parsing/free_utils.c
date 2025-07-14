/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:37:48 by jmehmy            #+#    #+#             */
/*   Updated: 2025/06/29 23:08:55 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_redirections(t_red *redir)
{
	t_red	*tmp;

	while (redir)
	{
		tmp = redir->next;
		free(redir->args);
		free(redir);
		redir = tmp;
	}
}

void	free_cmd(t_cmd **cmds)
{
	t_cmd	*tmp;
	int		i;

	if (!cmds || !*cmds)
		return ;
	while (*cmds)
	{
		tmp = (*cmds)->next;
		i = 0;
		if ((*cmds)->args)
		{
			while ((*cmds)->args[i])
				free((*cmds)->args[i++]);
			free((*cmds)->args);
		}
		free_redirections((*cmds)->redirect);
		free(*cmds);
		*cmds = tmp;
	}
}
