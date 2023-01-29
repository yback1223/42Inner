/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:16:09 by yback             #+#    #+#             */
/*   Updated: 2023/01/11 21:37:48 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **envp)
{
	int		fds[2];
	int		infile;
	int		outfile;
	pid_t	pid;

	infile = open(av[1], O_RDONLY, 0777);
	outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (infile | outfile == -1)
		error();
	if (ac == 5)
	{
		if (pipe(fds) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		child_process(av, envp, fds, infile);
	}
}

void	child_process(char **av, char **envp, int *fds, int infile)
{
	dup2(infile, STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	close(fds[0]);
	execute(av[2], envp);
}

void	execute(char *av, char **envp)
{
	char	**command;
	char	*path;
	
	command = ft_split(av, ' ');
	path = 
}