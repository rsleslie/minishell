/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:27:44 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/03 11:33:39 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../minishell.h"

void	exit_check(t_sys_config *data)
{
	if (ft_strncmp(data->str, "exit", ft_strlen(data->str) - 1) == 0)
	{
		printf("Bye!\n");
		exit(0);
	}
}

void	args_checks(int argc)
{
	if (argc != 1)
	{
		printf("Invalid number of arguments!\n");
		exit(0);
	}
}

void	signal_ctrl_d(char *data)
{
	if (data == NULL)
	{
		printf("Bye!\n");
		exit(0);
	}
}
