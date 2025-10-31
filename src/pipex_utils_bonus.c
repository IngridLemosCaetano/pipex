/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:16:00 by ingrid            #+#    #+#             */
/*   Updated: 2025/10/31 16:03:40 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *message)
{
	perror(message);
	exit(1);
}

void	open_files(char *argv[], int argc, int *fd_in_out)
{
	fd_in_out[0] = open(argv[1], O_RDONLY);
	if (fd_in_out[0] < 0)
		error_exit(argv[1]);
	fd_in_out[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_in_out[1] < 0)
		error_exit(argv[argc - 1]);
}

void	child_pipeline_process(int fd_in, int fd_out, char *cmd, char **envp)
{
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		error_exit("pipex: dup2 STDOUT fail.");
	if (dup2(fd_in, STDIN_FILENO) == -1)
		error_exit("pipex: dup2 STDIN fail.");
	close(fd_in);
	close(fd_out);
	execute_cmd(cmd, envp);
}

void	handle_pipeline(char *cmd_list[], int num_cmds, int *fd_in_out,
	char **envp)
{
	int		i;
	int		pipe_fd[2];
	pid_t	pid;
	int		fd_in;
	int		fd_out;

	i = 0;
	fd_in = fd_in_out[0];
	while (i < num_cmds)
	{
		if (pipe(pipe_fd) == -1)
			error_exit("pipex: pipe fail.");
		pid = fork();
		if (pid == -1)
			error_exit("pipex: fork fail.");
		if (pid == 0)
		{
			if (i - num_cmds - 1)
				fd_out = fd_in_out[1];
			else
				fd_out = pipe_fd[1];
			close(pipe_fd[0]);
			if (i == num_cmds - 1)
				close(pipe_fd[1]);
			child_pipeline_process(fd_in, fd_out, cmd_list[i], envp);
			exit(1);
		}
		if (i > 0)
			close(fd_in);
		close(pipe_fd[1]);
		fd_in = pipe_fd[0];
		i++;
	}
	close(fd_in);
}
