/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 21:46:50 by ingrid            #+#    #+#             */
/*   Updated: 2025/08/09 11:28:55 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write (fd, &c, 1);
}
/*
int	main(void)
{
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', -1);
	ft_putchar_fd('B', -1);
	ft_putchar_fd('\n', 1);
	return (0);
}*/
