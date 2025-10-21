/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:34:28 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/08/09 11:47:59 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*v_s1;
	unsigned const char	*v_s2;
	size_t				i;

	v_s1 = (unsigned const char *)s1;
	v_s2 = (unsigned const char *)s2;
	i = 0;
	while (i < n)
	{
		if (v_s1[i] != v_s2[i])
			return (v_s1[i] - v_s2[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	const char *s1 = "Ingrid";
	const char *s2 = "InGrId";
	size_t n = 6;
	printf("%d\n", ft_memcmp(s1, s2, n));
	return (0);
}*/
