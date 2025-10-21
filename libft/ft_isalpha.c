/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:40:23 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/07/31 11:33:58 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	int a = 'a';
	int z = 'Z';
	int i = '7';
	int n = 7;
	printf("%d\n",ft_isalpha(a));
	printf("%d\n",ft_isalpha(z));
	printf("%d\n",ft_isalpha(i));
	printf("%d\n",ft_isalpha(n));
	return (0);
}*/
