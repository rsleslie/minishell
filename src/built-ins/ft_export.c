/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:08:51 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/10 13:00:15 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_export(t_node **list, char *key)
{
	t_node	*current;
	t_node	*temp;
	int		i;

	i = 0;
	temp = creat_node(key);
	current = (*list);
	while (current != NULL)
	{
		if (search_env(temp->variable, current->variable) == 0)
		{
			i = 1;
			free(current->value);
			current->value = ft_strdup(temp->value);
			ft_free_node(temp);
			return;
		}
		current = current->next;
	}
	if (i == 0)
		link_node_end(list,creat_node(key));
	ft_free_node(temp);
}
