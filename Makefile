# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 00:41:45 by rleslie-          #+#    #+#              #
#    Updated: 2023/04/02 18:08:57 by rleslie-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= minishell
SRC= minishell.c ./src/minishell_utils.c ./src/handle_envp.c ./src/handle_parse.c ./src/handle_exec.c ./src/handle_paths.c
OBJ= $(.c=.o)
CC= cc
RL= -lreadline
FLAG= -Wall -Wextra -Werror
LIBFT= ./libft/libft.a

all: $(NAME) 

$(NAME): $(OBJ)
		@make -C libft
		$(CC) $(SRC) $(LIBFT) $(FLAG) $(RL) -o $(NAME)

clean:
		rm -f $(OBJ)
		@make fclean -C libft

fclean: clean
		rm -rf $(NAME)
		
re: fclean all