/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:04:06 by ingrid            #+#    #+#             */
/*   Updated: 2025/10/31 13:39:06 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

int		main(int argc, char *argv[], char *envp[]);
char	*find_full_command_path(char *envp[], char *cmd);
char	*ft_getenv(char *envp[]);
char	*join_path_cmd(char *path, char	*cmd);
void	ft_free_array(char **array);
void	execute_cmd(char *cmd_str, char *envp[]);
void	error_exit(char *message);
void	open_files(char *argv[], int argc, int *fd_in_out);
void	handle_pipeline(char *cmd_list[], int num_cmds, int *fd_in_out,
			char **envp);
void	child_pipeline_process(int fd_in, int fd_out, char *cmd, char **envp);

#endif
