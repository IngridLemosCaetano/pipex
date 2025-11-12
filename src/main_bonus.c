/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:11:58 by ingrid            #+#    #+#             */
/*   Updated: 2025/11/12 12:26:28 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	data[5];

	if (argc < 5)
	{
		ft_putstr_fd("Use: ./pipex infile \"cmd1\" \"cmd2\" \"cmdN\" ", 2);
		ft_putstr_fd("outfile\n", 2);
		return (1);
	}
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		ft_putstr_fd("This program does not support here_doc.\n", 2);
		return (1);
	}
	open_files(argv, argc, data);
	data[IDX_CMD] = 0;
	data[IDX_MAX] = argc - 3;
	data[FD_CURR] = data[0];
	handle_pipeline(&argv[2], data, envp);
	close(data[0]);
	close(data[1]);
	while (wait(NULL) > 0)
	{
	}
	return (0);
}
