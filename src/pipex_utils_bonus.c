/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:16:00 by ingrid            #+#    #+#             */
/*   Updated: 2025/11/12 20:06:50 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	open_files(char *argv[], int argc, int *data)
{
	data[FD_IN] = open(argv[1], O_RDONLY);
	if (data[FD_IN] < 0)
		error_exit("pipex: was not possible open infile.");
	data[FD_OUT] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data[FD_OUT] < 0)
		error_exit("pipex: was not possible open/create/truncate the outfile");
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

static void	process_cleanup(int data[], int pipe_fd[2])
{
	close(data[FD_CURR]);
	if (data[IDX_CMD] < data[IDX_MAX] - 1)
	{
		close(pipe_fd[1]);
		data[FD_CURR] = pipe_fd[0];
	}
}

static void	process_command(char *cmd, int data[], char *envp[])
{
	int		pipe_fd[2];
	int		fd_out;
	pid_t	pid;

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
		child_pipeline_process(data[FD_CURR], fd_out, cmd, envp);
	}
	process_cleanup(data, pipe_fd);
}

void	handle_pipeline(char *cmd_list[], int data[], char *envp[])
{
	while (data[IDX_CMD] < data[IDX_MAX])
	{
		process_command(cmd_list[data[IDX_CMD]], data, envp);
		data[IDX_CMD]++;
	}
	close(data[FD_CURR]);
}
