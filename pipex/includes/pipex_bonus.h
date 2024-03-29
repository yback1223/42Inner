/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:24:49 by yback             #+#    #+#             */
/*   Updated: 2023/02/09 16:22:18 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>

/* to libft */
# include "../libft/libft.h"

/* to gnl */
# include "../gnl/get_next_line.h"

# define ERR_INFILE 	"Infile"
# define ERR_OUTFILE 	"Outfile"
# define ERR_INPUT		"Invalid number of arguments.\n"
# define ERR_PIPE		"Pipe"
# define ERR_ENVP		"Environment"
# define ERR_CMD		"Command not found"
# define ERR_HEREDOC	"here_doc"

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
}				t_cmd;

typedef struct s_env
{
	char			**envp;
	int				n_cmd;
	int				here_doc;
	char			**hd_cmd;
	int				idx;
	int				i_fd;
	int				o_fd;
	int				*pipe_fd;
	int				result;
	char			**path;
	pid_t			pid;
	struct s_cmd	*cmd;
}				t_env;

/* parse_bonus.c */
void	parse_cmd(t_env *info, int argc, char **argv);
void	check_cmd(t_env *info, char **argv);
void	find_awk_sed(char **argv, int i, t_env *info);
void	find_awk_sed2(t_env *info, char **tmp_info, int i, int tmp);
char	*get_cmd_argv(char **path, char *cmd);

/* utils_bonus.c */
void	exit_perror(char *msg, int code);
void	split_free(char **to_free);
void	close_pipes(t_env *info);
char	*find_path(char **envp);

/* heredoc_bonus.c */
int		args_in(char *arg);
void	here_doc(char *argv, t_env *info);
void	get_fd(t_env *info, int argc, char **argv);
void	parent_free(t_env *info);

#endif
