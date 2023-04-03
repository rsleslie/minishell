/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:51:41 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/03 19:27:01 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_node	*node_list(char *data)
{
	t_node *aux;
	
	aux = malloc(sizeof(t_node));
	aux->str = ft_strdup(data);
	aux->next = NULL;
	return (aux);
}

t_node *node_last(t_node *list)
{
	t_node *aux;

	aux = list;
	while (aux->next != NULL)
		aux = aux->next;
	return (aux);		
}

void	link_node_end(t_node **data, t_node *node)
{
	t_node *aux;
	if(data == NULL)
		return;
	if (*data == NULL)
	{
		*data = node;
		return;
	}
	aux = node_last(*data);
	aux->next = node;
}	
