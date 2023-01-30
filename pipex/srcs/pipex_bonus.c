/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:31:05 by yback             #+#    #+#             */
/*   Updated: 2023/01/30 19:38:31 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limiter, int argc)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (argc < 6)
		exit(EXIT_SUCCESS);
	if (pipe(fd) == -1)
		error();
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			outfile = open_file(argv[argc - 1], 0);
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			outfile = open_file(argv[argc - 1], 1);
			infile = open_file(argv[1], 2);
			dup2(infile, STDIN_FILENO);
		}
		while (i < argc - 2)
			child_process(argv[i++], envp);
		dup2(outfile, STDOUT_FILENO);
		execute(argv[argc - 2], envp);
	}
	exit(EXIT_SUCCESS);
}