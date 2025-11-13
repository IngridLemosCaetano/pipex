/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:04:06 by ingrid            #+#    #+#             */
/*   Updated: 2025/11/13 11:27:28 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../lib/libft/inc/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

# define FD_IN 0
# define FD_OUT 1
# define IDX_CMD 2
# define IDX_MAX 3
# define FD_CURR 4

int		main(int argc, char *argv[], char *envp[]);
char	*find_full_command_path(char *envp[], char *cmd);
char	*ft_getenv(char *envp[]);
char	*join_path_cmd(char *path, char	*cmd);
void	ft_free_array(char **array);
void	execute_cmd(char *cmd_str, char *envp[]);
void	error_exit(char *message);
void	open_files(char *argv[], int argc, int *data);
void	child_pipeline_process(int fd_in, int fd_out, char *cmd, char *envp[]);
void	handle_pipeline(char *cmd_list[], int data[], char *envp[]);

#endif
