/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:19:51 by yback             #+#    #+#             */
/*   Updated: 2023/01/30 18:32:15 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(void)
{
	perror("Error ");
	exit(EXIT_FAILURE);
}

char	*get_path(char *command, char **envp)
{
	char	**paths;
	char	*path;
	char	*tmp_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	if (paths == 0)
		error();
	i = 0;
	while (paths[i])
	{
		tmp_path = ft_strjoin("/", command);
		path = ft_strjoin(paths[i], tmp_path);
		free(tmp_path);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	execute(char *av, char **envp)
{
	char	**cmd;
	int 	i;
	char	*path;
	
	i = -1;
	cmd = ft_split(av, ' ');
	path = get_path(cmd[0], envp);
	if (!path)	
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}
