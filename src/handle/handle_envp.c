/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:27:21 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/04 15:50:56 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	search_env(char *data, char *key)
{
	int	len_data = ft_strlen(data);
	int	len_key = ft_strlen(key);
	int	len;
	if (len_data > len_key)
		len = len_data;
	else
		len = len_key;
	if (ft_strncmp(data, key,len) == 0)
		return (0);	
	return (1);
}

void	add_env(t_node **list, char *key)
{
	t_node	*current;
	t_node	*temp;
	int		i;

	i = 0;
	temp = node_list(key);	
	current = (*list);
	while (current != NULL)
	{
		if (search_env(temp->variable, current->variable) == 0)
		{
			current->value = temp->value;
			i = 1;
		}
		current = current->next;
	}
	if (i == 0)
		link_node_end(list, node_list(key));
}

void	remove_env(t_node **list, char *key)
{
	t_node		*current;
	t_node		*temp;

	temp = NULL;
	current = (*list);
	while (current != NULL)
	{
		if (search_env(current->variable, key) == 0)
		{
			if (temp == NULL)
				(*list) = (*list)->next;
			else
				temp->next = current->next;
			return ;
		}
		temp = current;
		current = current->next;
	}
}

void	get_envp(t_node **env, char **envp)
{
	int		i;
	
	i = 0;
	while (envp[i])
	{
		link_node_end(env, node_list(envp[i]));
		i++;
	}
}
