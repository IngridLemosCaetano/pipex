/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:54:56 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/08/09 11:46:46 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	buffer[6] = "Ingrid";
	size_t	i = 0;

	ft_bzero(buffer, sizeof(buffer));
	while (i < sizeof(buffer))
	{
		printf("%d", buffer[i]);
		i++;
	}
	return (0);
}*/
