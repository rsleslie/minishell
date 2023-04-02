/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:27:21 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/02 18:22:32 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_envp(t_sys_config *data, char **envp)
{
	int	i;

	i = 0;
	data->env = (char **)malloc(sizeof(char *) * strlen_vars(envp) + 1);
	while (envp[i])
	{
		data->env[i] = ft_strdup(envp[i]);
		i++;
	}
	split_paths(data);
}


