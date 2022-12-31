/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:23:31 by yback             #+#    #+#             */
/*   Updated: 2022/12/31 20:45:13 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#define BUFFER_SIZE 100

char	*making_backup(int fd, char *backup)
{
	char		*tmp;
	int			num;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (0);
	num = 1;
	while (!ft_strchr_gnl(backup, '\n') && num)
	{
		num = read(fd, tmp, BUFFER_SIZE);
		if (num == -1)
		{
			free(tmp);
			return (0);
		}
		tmp[num] = 0;
		backup = ft_strjoin_gnl(backup, tmp);
	}
	free(tmp);
	return (backup);
}

char	*making_newbackup(char *backup)
{
	char	*newbackup;
	int		i;
	int		j;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	newbackup = malloc(ft_strlen_gnl(backup) - i + 1);
	if (!newbackup)
		return (0);
	if (backup[i] != '\n')
	{
		free(newbackup);
		newbackup = 0;
	}
	else
	{
		i++;
		j = 0;
		while (backup[i])
			newbackup[j++] = backup[i++];
		newbackup[j] = 0;
	}
	free(backup);
	return (newbackup);
}

char	*making_ans(char *backup)
{
	int		i;
	char	*ans;

	i = 0;
	if (!backup[i])
		return (0);
	while (backup[i] && backup[i] != '\n')
		i++;
	ans = (char *)malloc(i + 2);
	if (!ans)
		return (0);
	i = 0;
	while (backup[i] != '\n' && backup[i])
	{
		ans[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
		ans[i++] = '\n';
	ans[i] = 0;
	return (ans);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*ans;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = making_backup(fd, backup);
	if (!backup)
		return (0);
	ans = making_ans(backup);
	backup = making_newbackup(backup);
	return (ans);
}