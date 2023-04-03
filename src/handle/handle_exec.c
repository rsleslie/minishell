/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:10:54 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/03 11:55:50 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exec_stdin(t_sys_config *data)
{
	pid_t	pid;

	pid = fork();// cria o processo filho
	if (pid == -1)
	{
		// erro ao criar o processo filho
		perror("Erro ao criar processo filho");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		// código do processo filho
		char *args[] = {data->str_command[0], data->str_command[1], NULL};
		execvp(args[0], args);// substitui a imagem do processo filho pelo comando "ls -l"
	}
	else
	{
		// código do processo pai
		wait(NULL);// espera o processo filho terminar
	}
}
