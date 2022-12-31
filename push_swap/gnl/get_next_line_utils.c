/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:21:28 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/31 16:49:01 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// char	*ft_strchr(char *str, int c)
// {
// 	size_t	i;

// 	i = 0;
// 	if (str == 0)
// 		return (0);
// 	while (str[i] != 0)
// 	{
// 		if (str[i] == c)
// 			return ((char *)&str[i]);
// 		i++;
// 	}
// 	if (str[i] == c)
// 		return ((char *)&str[i]);
// 	return (0);
// }

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == 0)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s1 == 0 || s2 == 0)
		return (0);
	i = -1;
	j = 0;
	str = malloc (sizeof(char) * ((int)ft_strlen(s1) + (int)ft_strlen(s2) + 1));
	if (str == 0)
		return (0);
	while (s1[++i] != 0)
		str[i] = s1[i];
	while (s2[j] != 0)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	s1 = 0;
	return (str);
}
