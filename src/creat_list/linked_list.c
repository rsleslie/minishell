/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:51:41 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/04 14:50:52 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_node	*node_list(char *list)
{
	t_node	*aux;
	char	**split_list;

	split_list = ft_split(list, '=');
	aux = malloc(sizeof(t_node));
	aux->variable = ft_strdup(split_list[0]);
	aux->value = ft_strdup(split_list[1]);
	aux->next = NULL;
	free(split_list);
	return (aux);
}

t_node	*node_last(t_node *list)
{
	t_node	*aux;

	aux = list;
	while (aux->next != NULL)
		aux = aux->next;
	return (aux);
}

void	link_node_end(t_node **list, t_node *node)
{
	t_node	*aux;

	if (list == NULL)
		return ;
	if (*list == NULL)
	{
		*list = node;
		return ;
	}
	aux = node_last(*list);
	aux->next = node;
}

// int	main(int argc, char **argv)
// {
// 	t_node	*aux;
// 	t_node	*env = NULL;
// 	int		i = 1;

// 	while (argv[i])
// 	{
// 		link_node_end(&env, node_list(argv[i]));
// 		i++;
// 	}
// 	aux = env;
// 	while (aux)
// 	{
// 		printf("%s === %s\n", aux->variable, aux->value);
// 		aux = aux->next;
// 	}
// 	printf("\n");
// 	add_env(&env,"PATH_nova=trocou");
// 	aux = env;
// 	while (aux)
// 	{
// 		printf("%s === %s\n", aux->variable, aux->value);
// 		aux = aux->next;
// 	}
	
// 	//----------------------
// 	printf("\n remove \n\n");
// 	aux = env;
// 	while (aux)
// 	{
// 		printf("%s === %s\n", aux->variable, aux->value);
// 		aux = aux->next;
// 	}
// 	printf("\n");
// 	remove_env(&env,"PATH_KEY");
// 	aux = env;
// 	while (aux)
// 	{
// 		printf("%s === %s\n", aux->variable, aux->value);
// 		aux = aux->next;
// 	}
// }
