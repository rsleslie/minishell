/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:32:48 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/03 19:23:28 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_sys_config	data;
	int				i;
	
	i = 0;
	(void)argv;
	args_checks(argc);
	get_envp(&data, envp);
	while (1)
	{
		data.str = readline("MiniShell> ");
		signal_ctrl_d(data.str);
		add_history(data.str);
		// i = search_envp(data.str + 6, &data);
		// printf("%s\n", get_value_env(&data, i));
		exit_check(&data);
		split_command(&data);
	}
	return (0);
}
