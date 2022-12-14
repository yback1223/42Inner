/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:21:28 by hyunjung          #+#    #+#             */
/*   Updated: 2023/01/01 16:42:51 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	while (s[size])
		size++;
	if (c == 0)
		return ((char *)&s[size]);
	return (0);
}

char	*ft_strjoin_gnl(char *backup, char *tmp)
{
	char	*arr;
	int		i;
	int		tmp_i;

	if (!backup)
	{
		backup = (char *)malloc(1 * sizeof(char));
		backup[0] = 0;
	}
	if (!tmp)
		return (0);
	arr = (char *)malloc((ft_strlen_gnl(backup) + ft_strlen_gnl(tmp)) + 1);
	if (!arr)
		return (0);
	i = -1;
	while (backup[++i] && backup)
		arr[i] = backup[i];
	tmp_i = i;
	i = 0;
	while (tmp[i])
		arr[tmp_i++] = tmp[i++];
	arr[tmp_i] = 0;
	free(backup);
	return (arr);
}
