/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:57:27 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/03 11:33:25 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define SIMPLE_QUOTE 39
# define DOUBLE_QUOTE 34

# include <stdio.h>
# include "./libft/libft.h"
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_sys_config
{
	char	*str;
	char	**str_command;
	char	**env;
	char	**paths;
}	t_sys_config;

int		strlen_vars(char **envp);
void	get_envp(t_sys_config *data, char **envp);
void	split_command(t_sys_config *data);
void	exec_stdin(t_sys_config *data);
void	split_paths(t_sys_config *data);
void	free_struct(t_sys_config *data);

// check

void	exit_check(t_sys_config *data);
void	args_checks(int argc);
void	signal_ctrl_d(char *data);

#endif