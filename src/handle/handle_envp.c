/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:27:21 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/03 19:25:54 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

char	*get_value_env(t_sys_config *data, int i)
{
	char	**str;

	str = ft_split(data->env[i], '=');
	return (str[1]);	
}

int	search_envp(char *key, t_sys_config *data)
{
	int len_key;
	int	i;
	
	i = 0;
	len_key = ft_strlen(key);
	if (!key || !data->env)
		return (-1);
	while(data->env[i])
	{
		if (ft_strncmp(data->env[i], key, len_key) == 0)
		{
			if(len_key == keylen(data->env[i]))
				return (i);
		}
		i++;
	}
	return (-1);
}
