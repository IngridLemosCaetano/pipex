/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:59:54 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/08/09 11:48:42 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	to_uppercase(unsigned int n, char *c)
{
	(void)n;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

int	main(void)
{
	char	str[] = "Ingrid";
	ft_striteri(str, (void (*)(unsigned int, char *))to_uppercase);
	printf("%s\n", str);
	return (0);
}*/
