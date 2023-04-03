/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:57:27 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/03 19:25:18 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SIMPLE_QUOTE 39
# define DOUBLE_QUOTE 34

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
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

typedef struct s_node
{
	char	*str;
	struct s_node *next;
}	t_node;

// typedef struct s_linked_list
// {
	
// 	struct s_linked_list *next;
// }	t_linked_list;

//utils
int		strlen_vars(char **envp);
int		keylen(char *str);

//handle_envp
void	get_envp(t_sys_config *data, char **envp);
int		search_envp(char *key, t_sys_config *data);
char	*get_value_env(t_sys_config *data, int i);

// handle_exec .. executar comandos
void	exec_stdin(t_sys_config *data);

//handle_parse separa comando e analisa biltins variavel de ambiente..
void	split_command(t_sys_config *data);

//splita a split da envp
void	split_paths(t_sys_config *data);

// check
void	exit_check(t_sys_config *data);
void	args_checks(int argc);
void	signal_ctrl_d(char *data);

// creat_list
void	link_node_end(t_node **data, t_node *node);
t_node	*node_last(t_node *list);
t_node	*node_list(char *data);

#endif