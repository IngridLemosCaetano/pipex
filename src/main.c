/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:35:19 by ingrid            #+#    #+#             */
/*   Updated: 2025/10/29 12:40:47 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd_infile;
	int		fd_outfile;
	int		pipe_fd[2];
	pid_t	pid1;
	// int		i;
	// char	*cmd_valid;
	// char	**cmd_part1;
	if (argc != 5)
	{
		ft_printf("Invalid command, please try again.\n");
		ft_printf("Ex: ./pipex infile \"ls -l\" \"wc -l\" outfile\n");
		return (1);
	}
	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile < 0)
	{
		ft_printf("%s doesn't exit.\n", argv[1]);
		return (1);
	}
	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile < 0)
	{
		perror("falha outfile");
		return (1);
	}
	if (pipe(pipe_fd) == -1)
		return (1);
	// i = 2;
	// while (i <= 3)
	// {
	// 	cmd_part1 = ft_split(argv[i], ' ');
	// 	cmd_valid = find_full_command_path(envp, cmd_part1[0]);
	// 	if (!cmd_valid)
	// 		ft_printf("Invalid command: %s\n", argv[i]);
	// 	else
	// 		ft_printf("Command valid: %s\n", cmd_valid);
	// 	i++;
	// }
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(pipe_fd[0], STDOUT_FILENO);
		execute_cmd(argv[2], envp);
	}
	return (0);
}

// char	*is_cmd_valid(char	*cmd[], char	*envp[])
// {
// 	char	**cmd_parts;
// 	char	*c;
// 	int		i;
// 	int		j;
// 	int		x;

// 	i = 2;
// 	x = 0
// 	c = " :"
// 	while (i < 3)
// 	{
// 		cmd_parts = ft_split(cmd[i], c[x]);
// 		while (cmd_parts[j]);
// 			j++;
// 		if (j > 2 || !cmd_parts)
// 			return (NULL);
// 		while ()
// 		i++;
// 		x++;
// 	}
// }
