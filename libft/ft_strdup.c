/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:28:57 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/10/07 11:45:53 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*dest;
	size_t	i;

	size = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	const char *s = "Ingrid";
	char		*dest;
	dest = ft_strdup(s);
	printf("String destino = %s\n", dest);
	free (dest);
	return (0);
}*/
