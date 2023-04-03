/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:32:48 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/03 11:33:17 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_sys_config	data;
		
	(void)argv;
	args_checks(argc); // ve a quantidade de argumento na hora de executar o minishell
	get_envp(&data, envp); //pega a envip e joga da varial **env da struct
	while (1)
	{
		data.str = readline("MiniShell> ");
		signal_ctrl_d(data.str); // trata o ctrl+D, precisa fechar o processo
		add_history(data.str);
		exit_check(&data);// verifica se data.str é exit
		split_command(&data); // splita a path
	}
	return (0);
}
