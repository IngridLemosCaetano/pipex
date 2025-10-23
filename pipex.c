/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:36:21 by ingrid            #+#    #+#             */
/*   Updated: 2025/10/23 11:34:09 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_printf("O programa %s não recebeu nenhum argumento.\n", argv[0]);
		ft_printf("Ex: arquivo1 comando1 comando2 arquivo2\n");
	}
	else if (argc > 5)
		ft_printf("Argumentos acima do permitido.\n");
	else
	{
		ft_printf("Argumento 1 : %s\n", argv[1]);
		ft_printf("Argumento 2 : %s\n", argv[2]);
		ft_printf("Argumento 3 : %s\n", argv[3]);
		ft_printf("Argumento 4 : %s\n", argv[4]);
		ft_printf("Uhuuu!!! só sucesso!\n");
	}
	return (0);
}
