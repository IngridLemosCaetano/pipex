/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:34:00 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/08/09 11:47:55 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*v_s;

	i = 0;
	v_s = (const unsigned char *)s;
	while (i < n)
	{
		if (v_s[i] == (unsigned char)c)
			return ((void *)&v_s[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *s = "Ingrid";
	int c = 'i';

	char *ptr = ft_memchr(s, c, 6);
	if (ptr != NULL)
		printf("Caracter encontrado: %c.\n", *ptr);
	else
		printf("Caracter não encontrado.\n");
	return (0);
}*/
