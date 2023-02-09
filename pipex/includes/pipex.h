/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:17:24 by yback             #+#    #+#             */
/*   Updated: 2023/02/09 16:22:33 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>

/* to libft */
# include "../libft/libft.h"

# define ERR_INFILE 	"Infile"
# define ERR_OUTFILE 	"Outfile"
# define ERR_PIPE		"Pipe"
# define ERR_ENVP		"Environment"
# define ERR_CMD		"Command not found"

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
}				t_cmd;

typedef struct s_env
{
	char			**envp;
	int				idx;
	int				i_fd;
	int				o_fd;
	int				pipe_fd[2];
	int				result;
	char			**path;
	pid_t			pid;
	struct s_cmd	*cmd;
}				t_env;

/* parse.c */
void	parse_cmd(t_env *info, int argc, char **argv);
void	check_cmd(t_env *info, char **argv);
void	find_awk_sed(char **argv, int i, t_env *info);
void	find_awk_sed2(t_env *info, char **tmp_info, int i, int tmp);
char	*get_cmd_argv(char **path, char *cmd);

/* utils.c */
void	exit_perror(char *msg, int code);
void	split_free(char **to_free);
void	close_pipes(t_env *info);
char	*find_path(char **envp);

/* fd.c */
void	get_fd(t_env *info, int argc, char **argv);
void	parent_free(t_env *info);

#endif
