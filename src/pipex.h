/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:37:19 by ingrid            #+#    #+#             */
/*   Updated: 2025/10/29 16:26:55 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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
void	handle_first_cmd(int *pipe_fd, int fd_infile, char *cmd1_str, char *envp[]);
void	handle_second_cmd(int *pipe_fd, int fd_outfile, char *cmd2_str, char *envp[]);

#endif
