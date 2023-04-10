#include "../../minishell.h"

int	main(int argc, char **argv)
{
	t_node	*aux;
	t_node	*env = NULL;
	int		i = 1;

	argc = 0;
	while (argv[i])
	{
		link_node_end(&env, creat_node(argv[i]));
		i++;
	}
	aux = env;
	printf("\n------------------------------------------------\n");
	printf("\nValor de entrada env\n");
	while (aux)
	{
		printf("%s === %s\n", aux->variable, aux->value);
		aux = aux->next;
	}
	printf("\n------------------------------------------------\n");
	printf("ADD um valor em uma variavel que exite > PATH=trocou\n");
	ft_export(&env,"PATH=trocou");
	aux = env;
	while (aux)
	{
		printf("%s === %s\n", aux->variable, aux->value);
		aux = aux->next;
	}
	printf("\n------------------------------------------------\n");
	printf("\nADD uma variavel que NÂO exite > PATH_nova=value\n");
	ft_export(&env,"PATH_nova=value");
	aux = env;
	while (aux)
	{
		printf("%s === %s\n", aux->variable, aux->value);
		aux = aux->next;
	}
	
	printf("\n------------------------------------------------\n");
	printf("\nRemove PATH\n");
	ft_unset(&env,"PATH");
	aux = env;
	while (aux)
	{
		printf("%s === %s\n", aux->variable, aux->value);
		aux = aux->next;
	}
	printf("\n------------------------------------------------\n");
	printf("\nRemove PATH_nova\n");
	ft_unset(&env,"PATH_nova");
	aux = env;
	while (aux)
	{
		printf("%s === %s\n", aux->variable, aux->value);
		aux = aux->next;
	}
	printf("\n------------------------------------------------\n");
	ft_free_list(env);
}

//  gcc ../../src/free/ft_free_list.c ../../src/creat_list/linked_list.c ../../src/handle/handle_envp.c ../../libft/ft_strdup.c ../../libft/ft_strlen.c ../../libft/ft_strncmp.c ../../libft/ft_split.c ../../libft/ft_substr.c main.c ../../src/built-ins/ft_unset.c ../../src/built-ins/ft_export.c

//valgrind ./a.out PATH=bin/src USER=rleslie-

// valgrind --leak-check=full --show-leak-kinds=all --quiet ./a.out PATH=bin/src USER=rleslie-