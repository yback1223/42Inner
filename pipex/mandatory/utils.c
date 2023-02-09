/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:16:47 by yback             #+#    #+#             */
/*   Updated: 2023/02/09 15:48:05 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_perror(char *msg, int code)
{
	perror(msg);
	exit(code);
}

void	split_free(char **to_free)
{
	free(*to_free);
	*to_free = NULL;
}

void	close_pipes(t_env *info)
{
	int	i;

	i = -1;
	while (++i < 2)
		close(info->pipe_fd[i]);
}

char	*find_path(char **envp)
{
	int		i;
	char	*ret_path;

	i = -1;
	while (envp[++i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			ret_path = ft_strdup(envp[i] + 5);
			return (ret_path);
		}
	}
	return (NULL);
}
