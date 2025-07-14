/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:31:48 by jmehmy            #+#    #+#             */
/*   Updated: 2025/03/07 11:13:36 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1, len2;
	size_t	i, j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);  // Do this BEFORE using s1 or s2

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	
	i = 0;
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

/*
int main ()
{
	char *s1 = "Hello ";
	char    *s2 = "World";
	printf ("%s", ft_strjoin(s1,s2));
}*/
