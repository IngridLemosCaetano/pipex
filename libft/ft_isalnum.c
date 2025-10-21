/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:14:18 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/07/31 11:51:14 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	int n1 = 0;
	int n2 = '9';
	int a = 'a';
	int z = ' ';
	printf("%d\n", ft_isalnum(n1));
	printf("%d\n", ft_isalnum(n2));
	printf("%d\n", ft_isalnum(a));
	printf("%d\n", ft_isalnum(z));
	return (0);
}*/
