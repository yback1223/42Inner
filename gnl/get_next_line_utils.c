/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:24:53 by yback             #+#    #+#             */
/*   Updated: 2022/08/10 19:34:37 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
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

char	*ft_strjoin(char *backup, char *tmp)
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
	arr = (char *)malloc((ft_strlen(backup) + ft_strlen(tmp)) + 1);
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
