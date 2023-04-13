/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:57:27 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/13 14:19:14 by rleslie-         ###   ########.fr       */
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
	// char	**envp;
	char	**paths;
}	t_sys_config;

typedef struct s_node
{
	char	*variable;
	char	*value;
	struct s_node *next;
}	t_node;

//utils
int		strlen_vars(char **envp);
int		keylen(char *str);

//handle_envp
void	get_envp(t_node **env, char **envp);
int		search_env(char *data, char *key);
void	ft_print_env(t_node *env);

//built-ins
void	ft_export(t_node **list, char *key);
void	ft_print_export(t_node *env);
void	get_export(t_node **export, char **envp);
int	ft_lurkstr(const char *s, int c);
//---------------------
void	ft_unset(t_node **list, char *key);

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
t_node	*creat_node(char *data);
t_node	*creat_node_export(char *data);
t_node	*creat_node_export_test(char *data);

//free
void	ft_free_list(t_node *list);
void	ft_free_node(t_node *data);
void	ft_free_tab(char **str);

//test parse token
void	split_data_str(t_sys_config *data, t_node *env, t_node *export);

#endif