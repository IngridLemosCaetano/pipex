/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:03:44 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/08/09 11:49:07 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*new_s1;
	unsigned char	*new_s2;

	i = 0;
	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	while ((new_s1[i] != '\0' || new_s2[i] != '\0') && i < n)
	{
		if (new_s1[i] != new_s2[i])
			return (new_s1[i] - new_s2[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	const char *s1 = "Ingrid";
	const char *s2 = "InGrId";
	size_t n = 3;
	printf("%d\n", ft_strncmp(s1, s2, n));
	return (0);
}*/
