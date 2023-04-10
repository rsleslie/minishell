#include "../../minishell.h"

int main(int argc, char **argv)
{
    char *str;

    str = ft_strdup(argv[1]);
    printf("\nstr : %s \n", str);
    free(str);
    return(0);
}