/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 22:03:27 by ingrid            #+#    #+#             */
/*   Updated: 2025/08/09 11:59:18 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (s)
		write(fd, s, ft_strlen(s));
}
/*
int	main(void)
{
	ft_putstr_fd("\nend!", -1);
	return (0);
}*/
