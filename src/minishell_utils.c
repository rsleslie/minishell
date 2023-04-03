/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:18:07 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/03 15:26:20 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	strlen_vars(char **envp)
{
	int	len;

	len = 0;
	while (*envp)
	{
		envp++;
		len++;
	}
	return (len);
}

int	keylen(char *str)
{
	int		i;
	char	**split_str;

	split_str = ft_split(str, '=');
	i = ft_strlen(split_str[0]);
	free(split_str);
	return (i);
}
