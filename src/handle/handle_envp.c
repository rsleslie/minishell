/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:27:21 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/11 17:40:12 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_print_env(t_node *env)
{
	t_node *temp;
	
	temp = env;
	while(temp != NULL)
	{
		printf("%s=%s\n", temp->variable, temp->value);
		temp = temp->next;
	}
}

int	search_env(char *data, char *key)
{
	int	len_data;
	int	len_key;

	len_data = ft_strlen(data);
	len_key = ft_strlen(key);
	if (len_data == len_key)
	{
		if (ft_strncmp(data, key,len_data) == 0)
			return (0);
	}	
	return (1);
}

void	get_envp(t_node **env, char **envp)
{
	int		i;
	
	i = 0;
	while (envp[i])
	{
		link_node_end(env, creat_node(envp[i]));
		i++;
	}
}
