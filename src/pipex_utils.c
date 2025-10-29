/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:38:23 by ingrid            #+#    #+#             */
/*   Updated: 2025/10/29 16:26:45 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_first_cmd(int *pipe_fd, int fd_infile, char *cmd1_str, char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (!pid)
		perror("pipex: fork fails for cmd1");
	if (pid == 0)
	{
		if (dup2(pipe_fd[0], STDOUT_FILENO) == -1)
		{
			perror("pipex: dup2 STDOUT fails.");
			exit(1);
		}
		if (dup2(fd_infile, STDIN_FILENO) == -1)
		{
			perror("pipex: dup2 STDIN fails.");
		}
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(fd_infile);
		execute_cmd(cmd1_str, envp);
	}
	close(pipe_fd[1]);
}

void	handle_second_cmd(int *pipe_fd, int fd_outfile, char *cmd2_str, char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (!pid)
		perror("pipex: fork fails for cmd2");
	if (pid == 0)
	{
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		{
			perror("pipex: dup2 STDIN fails.");
			exit(1);
		}
		if (dup2(fd_outfile, STDOUT_FILENO) == -1)
		{
			perror("pipex: dup2 STDOUT fails");
			exit(1);
		}
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(fd_outfile);
		execute_cmd(cmd2_str, envp);
	}
	close(pipe_fd[0]);
}
