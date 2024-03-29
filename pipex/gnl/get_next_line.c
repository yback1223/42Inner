/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:19:17 by yback             #+#    #+#             */
/*   Updated: 2023/02/01 10:19:26 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strdup(const char *s1, int size)
{
	char	*cp;
	int		i;

	cp = (char *)malloc(sizeof(char) * (size + 1));
	if (cp == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i < size)
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

static char	*read_line(char **backup, char *buf)
{
	char	*ret;
	char	*new_backup;
	int		n_b_s;

	ret = NULL;
	if (gnl_strchr(*backup) == -1)
	{
		if (*backup[0] != '\0')
			ret = ft_strdup(*backup, gnl_strlen(*backup));
		free(*backup);
		*backup = NULL;
	}
	else
	{
		ret = ft_strdup(*backup, gnl_strchr(*backup) + 1);
		n_b_s = gnl_strlen(*backup + gnl_strchr(*backup) + 1);
		new_backup = ft_strdup((*backup + gnl_strchr(*backup) + 1), n_b_s);
		free(*backup);
		*backup = new_backup;
	}
	free(buf);
	return (ret);
}

static char	*read_buf(int fd, char **backup, char *buf)
{
	ssize_t	read_size;
	char	*new_backup;

	buf[BUFFER_SIZE] = '\0';
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		new_backup = gnl_strjoin(*backup, buf);
		free(*backup);
		*backup = new_backup;
		if (gnl_strchr(*backup) != -1)
			return (read_line(backup, buf));
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (read_line(backup, buf));
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
	{
		free(buf);
		return (NULL);
	}
	if (backup != NULL && gnl_strchr(backup) != -1)
		return (read_line(&backup, buf));
	if (backup == NULL)
	{
		backup = (char *)malloc(sizeof(char));
		if (!backup)
			return (NULL);
		backup[0] = '\0';
	}
	return (read_buf(fd, &backup, buf));
}
