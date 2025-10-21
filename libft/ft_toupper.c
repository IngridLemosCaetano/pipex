/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:14:19 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/07/22 14:41:17 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
int	main(void)
{
	int	v1 = 'C';
	int	v2 = 'c';
	int	v3 = 'I';
	int	v4 = '9';
	printf("%c\n", ft_toupper(v1));
	printf("%c\n", ft_toupper(v2));
	printf("%c\n", ft_toupper(v3));
	printf("%c\n", ft_toupper(v4));
}*/
