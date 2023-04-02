/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 22:44:09 by coder             #+#    #+#             */
/*   Updated: 2023/01/23 16:01:50 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	while (s[i])
		i++;
	ptr = (unsigned char *)malloc((i * sizeof(char)) + 1);
	if (ptr == NULL)
		return (NULL);
	else
	{	
		i = 0;
		while (s[i] != '\0')
		{
			ptr[i] = s[i];
			i++;
		}
	}
	ptr[i] = '\0';
	return ((char *)ptr);
}
