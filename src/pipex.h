/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:37:19 by ingrid            #+#    #+#             */
/*   Updated: 2025/10/29 10:32:03 by ingrid           ###   ########.fr       */
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
char	*find_full_command_path(char	*envp[], char	*cmd);
char	*ft_getenv(char	*envp[]);
char	*join_path_cmd(char	*path, char	*cmd);
void	ft_free_array(char	**array);
void	execute_cmd(char	*cmd_str, char	*envp[]);

#endif
