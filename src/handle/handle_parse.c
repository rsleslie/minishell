/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:37:17 by rleslie-          #+#    #+#             */
/*   Updated: 2023/04/13 15:56:44 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_lurkstr(const char *s, int c)
{
	int	i;

	i = 0;
	
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_key_parser(char *key)
{
	char	**split_key;

	if (ft_lurkstr(key, '=') == 0)
	{
		split_key = ft_split(key, '=');
		if (split_key[1] == NULL)
			return (0);
		else
			return (1);
	}
	return (2);
}

void	parse_unset_export(char **split_data_str, t_node *env, t_node *export)
{
	int i;

	i = 1;	
    if (ft_strncmp(split_data_str[0], "env", ft_strlen(split_data_str[0])) == 0 && !split_data_str[1])
        ft_print_env(env);
    else if (ft_strncmp(split_data_str[0], "export", ft_strlen(split_data_str[0])) == 0 && !split_data_str[1])
        ft_print_export(export);
    else if (ft_strncmp(split_data_str[0], "export", ft_strlen(split_data_str[0])) == 0)
    {
		while (split_data_str[i])
		{
			if (ft_lurkstr(split_data_str[i], '=') == 1)
				ft_export(&export, split_data_str[i]);
			else
			{
				ft_export(&export, split_data_str[i]);
				ft_export(&env, split_data_str[i]);	
			}
			i++;
		}
			
    } 
    else if (ft_strncmp(split_data_str[0], "unset", ft_strlen(split_data_str[0])) == 0 && !split_data_str[1])
        printf("unset: not enough arguments\n");
    else if (ft_strncmp(split_data_str[0], "unset", ft_strlen(split_data_str[0])) == 0)
    {
        ft_unset(&export, split_data_str[1]);
        ft_unset(&env, split_data_str[1]);
    }
	// parse_test_export(split_data_str, env, export);
}

/* 
export OI= tbm vai para o env
*/

void	split_data_str(t_sys_config *data, t_node *env, t_node *export)
{
	char	**split_data_str;
	int		i = 0;

	split_data_str = ft_split(data->str, 32);
	while (split_data_str[i])
		i++;
	parse_unset_export(split_data_str, env, export);
}
