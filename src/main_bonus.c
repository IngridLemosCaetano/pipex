/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:11:58 by ingrid            #+#    #+#             */
/*   Updated: 2025/10/31 13:36:09 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	// int	fd_infile;
	// int	fd_outfile;
	int	fd_in_out[2];
	int	num_cmds;

	num_cmds = argc - 3;
	if (argc < 5)
	{
		ft_putstr_fd("Use: ./pipex infile \"cmd1\" \"cmd2\" \"cmdN\" outfile\n", 2);
		return (1);
	}
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		ft_putstr_fd("This program does not support here_doc.\n", 2);
		return (1);
	}
	open_files(argv, argc, fd_in_out);
	handle_pipeline(&argv[2], num_cmds, fd_in_out, envp);
	close(fd_in_out[0]);
	close(fd_in_out[1]);
	while (wait(NULL) > 0);
	return (0);
}
