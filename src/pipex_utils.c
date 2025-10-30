/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:38:23 by ingrid            #+#    #+#             */
/*   Updated: 2025/10/30 15:06:59 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_first_cmd(int *pipe_fd, int fd_infile, char *cmd1_str,
	char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("pipex: fork fails for cmd1.");
		exit(1);
	}
	if (pid == 0)
	{
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			error_exit("pipex: dup2 STDOUT fails.");
		if (dup2(fd_infile, STDIN_FILENO) == -1)
			error_exit("pipex: dup2 STDIN fails.");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(fd_infile);
		execute_cmd(cmd1_str, envp);
	}
	close(pipe_fd[1]);
}

void	handle_second_cmd(int *pipe_fd, int fd_outfile, char *cmd2_str,
	char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("pipex: fork fails for cmd2.");
		exit(1);
	}
	if (pid == 0)
	{
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			error_exit("pipex: dup2 STDIN fails.");
		if (dup2(fd_outfile, STDOUT_FILENO) == -1)
			error_exit("pipex: dup2 STDOUT fails.");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(fd_outfile);
		execute_cmd(cmd2_str, envp);
	}
	close(pipe_fd[0]);
}

void	error_exit(char *message)
{
	perror(message);
	exit(1);
}
