/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:32:48 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/02 20:43:05 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_check(char *str, t_sys_config *data)
{
	if (ft_strncmp(str, "exit", ft_strlen(str) - 1) == 0)
	{
		printf("Bye!\n");
		free_struct(data);
		exit(0);
	}
}

void	free_struct(t_sys_config *data)
{
	int i;

	i = 0;
	free(data->str);
	while (data->env[i])
		free(data->env[i++]);
	i = 0;
	while (data->paths[i])
		free(data->paths[i++]);
	i = 0;
	while (data->str_command[i])
		free(data->str_command[i++]);	
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

int		signal_ctrl_c(char *data)
{
	if (ft_strncmp("^C", data, 2) == 0)
		return (0);
	return (1);
}
int	main(int argc, char **argv, char **envp)
{
	t_sys_config	data;
		
	(void)argv;
	args_checks(argc);
	get_envp(&data, envp);
	while (1)
	{
		data.str = readline("MiniShell> ");
		signal_ctrl_d(data.str);
		add_history(data.str);
		exit_check(data.str, &data);
		split_command(&data);
	}
	return (0);
}
