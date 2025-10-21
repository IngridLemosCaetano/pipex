/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:00:14 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/07/29 19:21:01 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int	main(void)
{
	int	n1 = 0;
	int	n2 = 9;
	int	n3 = '0';
	int	n4 = 'c';

	printf("%d\n", ft_isdigit(n1));
	printf("%d\n", ft_isdigit(n2));
	printf("%d\n", ft_isdigit(n3));
	printf("%d\n", ft_isdigit(n4));
}*/
