/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:03:16 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/02 18:24:43 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void	split_paths(t_sys_config *data)
{
	int	i;
	
	i = 0;
	while (ft_strncmp("PATH", data->env[i], 4))
		i++;
	data->paths = ft_split((data->env[i] + 5), ':');
}
