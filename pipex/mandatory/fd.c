/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:15:44 by yback             #+#    #+#             */
/*   Updated: 2023/02/01 10:16:14 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_fd(t_env *info, int argc, char **argv)
{
	info->i_fd = open(argv[1], O_RDONLY);
	if (info->i_fd < 0)
		perror(ERR_INFILE);
	info->o_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (info->o_fd < 0)
		exit_perror(ERR_OUTFILE, 1);
}

void	parent_free(t_env *info)
{
	close(info->i_fd);
	close(info->o_fd);
}
