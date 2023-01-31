/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:37:11 by yback             #+#    #+#             */
/*   Updated: 2023/01/31 11:42:29 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../includes/macros.h"

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, TOP_PERMISSION);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, TOP_PERMISSION);
	else if (i == 2)
		file = open(argv, O_RDONLY, TOP_PERMISSION);
	if (file == -1)
		error();
	return (file);
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		read_amount;
	char	oneCharacter;

	i = 0;
	read_amount = 0;
	buffer = (char *)malloc(ENOUGH_SPACE);
	if (!buffer)
		return (-1);
	read_amount = read(STDIN_FILENO, &oneCharacter, 1);
	while (read_amount && oneCharacter != NEW_LINE && oneCharacter != THE_END)
	{
		if (oneCharacter != NEW_LINE && oneCharacter != THE_END)
			buffer[i] = oneCharacter;
		i++;
		read_amount = read(STDIN_FILENO, &oneCharacter, 1);
	}
	buffer[i] = NEW_LINE;
	buffer[i + 1] = THE_END;
	*line = buffer;
	free(buffer);
	return (read_amount);
}

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
