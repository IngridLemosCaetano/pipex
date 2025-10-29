/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:36:21 by ingrid            #+#    #+#             */
/*   Updated: 2025/10/29 16:28:17 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_full_command_path(char *envp[], char *cmd)
{
	char	**paths_array;
	char	*path_result;
	char	*paths_str;
	int		i;

	paths_str = ft_getenv(envp);
	if (!paths_str)
		return (NULL);
	paths_array = ft_split(paths_str, ':');
	if (!paths_array)
		return (NULL);
	i = 0;
	while (paths_array[i])
	{
		path_result = join_path_cmd(paths_array[i], cmd);
		if (access(path_result, X_OK) == 0)
		{
			ft_free_array(paths_array);
			return (path_result);
		}
		free(path_result);
		i++;
	}
	ft_free_array(paths_array);
	return (NULL);
}

char	*ft_getenv(char *envp[])
{
	int		i;
	char	*path_key;

	i = 0;
	path_key = "PATH=";
	while (envp[i])
	{
		if (ft_strnstr(envp[i], path_key, ft_strlen(path_key)))
			return (envp[i] + ft_strlen(path_key));
		i++;
	}
	return (NULL);
}

char	*join_path_cmd(char *path, char *cmd)
{
	char	*aux;
	char	*path_cmd;

	aux = ft_strjoin(path, "/");
	if (!aux)
		return (NULL);
	path_cmd = ft_strjoin(aux, cmd);
	free(aux);
	return (path_cmd);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	execute_cmd(char *cmd_str, char *envp[])
{
	char	**cmd_array;
	char	*full_path;

	cmd_array = ft_split(cmd_str, ' ');
	if (!cmd_array)
		exit(1);
	full_path = find_full_command_path(envp, cmd_array[0]);
	if (!full_path)
	{
		ft_printf("pipex: command not found: %s\n", cmd_array[0]);
		ft_free_array(cmd_array);
		exit(127);
		if (execve(full_path, cmd_array, envp) == -1)
		{
			perror("execve failed\n");
			ft_free_array(cmd_array);
			free(full_path);
			exit(1);
		}
	}
}
