/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:32:48 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/11 17:18:38 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_sys_config	data;
	t_node			*env;
	t_node			*export;
	
	env = NULL;
	export = NULL;
	(void)argv;
	args_checks(argc);
	get_envp(&env, envp);
	get_envp(&export, envp);
	while (1)
	{
		data.str = readline("MiniShell> ");
		add_history(data.str);
		exit_check(&data);
		split_data_str(&data, env, export);
	}
	return (0);
}
