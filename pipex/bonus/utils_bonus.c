/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:23:39 by yback             #+#    #+#             */
/*   Updated: 2023/02/01 10:23:41 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/pipex_bonus.h"

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

void	usage(void)
{
	ft_putstr_fd("\033[31mError: Bad argument\n\e[0m", 2);
	ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("    ./pipex \"here_doc\" ", 1);
	ft_putstr_fd("<LIMITER> <cmd1> <cmd2> <...> <file>\n", 1);
	exit(EXIT_FAILURE);
}

void	close_pipes(t_env *info)
{
	int	i;

	i = 0;
	while (i < 2 * (info->n_cmd - 1))
	{
		close(info->pipe_fd[i]);
		i++;
	}
}

char	*find_path(char **envp)
{
	int		i;
	char	*ret_path;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			ret_path = ft_strdup(envp[i] + 5);
			return (ret_path);
		}
		i++;
	}
	return (NULL);
}
