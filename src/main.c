/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:35:19 by ingrid            #+#    #+#             */
/*   Updated: 2025/10/30 14:35:31 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd_infile;
	int		fd_outfile;
	int		pipe_fd[2];

	if (argc != 5)
	{
		ft_putstr_fd("Use: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 2);
		exit(1);
	}
	fd_infile = open(argv[1], O_RDONLY);
	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_infile < 0 || fd_outfile < 0)
		error_exit("pipex");
	if (pipe(pipe_fd) == -1)
		error_exit("pipex: pipe fails.");
	handle_first_cmd(pipe_fd, fd_infile, argv[2], envp);
	handle_second_cmd(pipe_fd, fd_outfile, argv[3], envp);
	close(fd_infile);
	close(fd_outfile);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	close(fd_infile);
	close(fd_outfile);
	return (0);
}
