/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:19:51 by yback             #+#    #+#             */
/*   Updated: 2023/01/11 22:20:37 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error ");
	exit(EXIT_FAILURE);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	int		i;
	int		tmp_i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	arr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!arr)
		return (0);
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	tmp_i = i;
	i = 0;
	while (s2[i])
		arr[tmp_i++] = s2[i++];
	arr[tmp_i] = 0;
	return (arr);
}

void	get_path(char *command, char **envp)
{
	char	**paths;
	char	*path;
	char	*tmp;
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
		tmp = ft_strjoin("/", command);
		path = ft_strjoin(paths[i], tmp);
		free(tmp);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}
}