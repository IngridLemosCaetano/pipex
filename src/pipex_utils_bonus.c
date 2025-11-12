/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:16:00 by ingrid            #+#    #+#             */
/*   Updated: 2025/11/12 12:40:08 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *message)
{
	perror(message);
	exit(1);
}

void	open_files(char *argv[], int argc, int *data)
{
	data[FD_IN] = open(argv[1], O_RDONLY);
	if (data[FD_IN] < 0)
		error_exit(argv[1]);
	data[FD_OUT] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data[FD_OUT] < 0)
		error_exit(argv[argc - 1]);
}

void	child_pipeline_process(int fd_in, int fd_out, char *cmd,
	char *envp[])
{
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		error_exit("pipex: dup2 STDOUT fail.");
	if (dup2(fd_in, STDIN_FILENO) == -1)
		error_exit("pipex: dup2 STDIN fail.");
	close(fd_in);
	close(fd_out);
	execute_cmd(cmd, envp);
}

// void	pipe_child(int **fd_in_out_i_ncmd, int *pipe_fd, char *cmd_list[],
// 	char *envp[])
// {
// 	int	fd_in;
// 	int	fd_out;

// 	if (fd_in_out_i_ncmd[0][3] == fd_in_out_i_ncmd[1][0] - 1)
// 	{
// 		fd_out = fd_in_out_i_ncmd[0][1];
// 		close(pipe_fd[1]);
// 	}
// 	else
// 		fd_out = pipe_fd[1];
// 	close(pipe_fd[0]);
// 	child_pipeline_process(data[FD_IN], fd_out, data[IDX_CMD], envp);
// 	exit(1);
// }

void	handle_pipeline(char *cmd_list[], int data[], char *envp[])
{
	int		pipe_fd[2];
	pid_t	pid;
	int		fd_out;

	while (data[IDX_CMD] < data[IDX_MAX])
	{
		if (data[IDX_CMD] < data[IDX_MAX] - 1)
		{
			if (pipe(pipe_fd) == -1)
				error_exit("pipex: pipe fail.");
			fd_out = pipe_fd[1];
		}
		else
			fd_out = data[FD_OUT];
		pid = fork();
		if (pid == -1)
			error_exit("pipex: fork fail.");
		if (pid == 0)
		{
			if (data[IDX_CMD] < data[IDX_MAX] -1)
				close(pipe_fd[0]);
			child_pipeline_process(data[FD_CURR], fd_out,
				cmd_list[data[IDX_CMD]], envp);
		}
		close(data[FD_CURR]);
		if (data[IDX_CMD] < data[IDX_MAX] -1)
		{
			close(pipe_fd[1]);
			data[FD_CURR] = pipe_fd[0];
		}
		data[IDX_CMD]++;
	}
	close(data[FD_CURR]);
}
