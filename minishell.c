/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:32:48 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/10 11:24:54 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_sys_config	data;
	t_node			*env;
	int				i;
	
	i = 0;
	env = NULL;
	(void)argv;
	args_checks(argc);
	get_envp(&env, envp);
	while (1)
	{
		data.str = readline("MiniShell> ");
		add_history(data.str);
		exit_check(&data);
	}
	return (0);
}
