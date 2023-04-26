/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:03:13 by agenoves          #+#    #+#             */
/*   Updated: 2022/05/16 12:11:50 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HANDLING PIPE IN SHELL

/* DUP2 -> int dup2 (int oldfd, int newfd).
La funzione dup2 crea una copia del descrittore di file specificato
e gli assegna un nuovo numero intero.
dup2 accetta un vecchio descrittore di file da clonare come primo parametro e
il secondo parametro è il numero intero per un nuovo descrittore di file. 
Torna -1 in caso di errore */

#include "pipex.h"	

void	ft_childprocess(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		ft_error();
	dup2(fd[1], 1);
	dup2(filein, 0);
	close(fd[0]);
	ft_exec(argv[2], envp);
}

void	ft_parentprocess(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
		ft_error();
	dup2(fd[0], 0);
	dup2(fileout, 1);
	close(fd[1]);
	ft_exec(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		status;
	pid_t	par;

	if (argc == 5)
	{
		pipe(fd);
		if (pipe(fd) == -1)
			ft_error();
		par = fork();
		if (par < 0)
			ft_error();
		if (par == 0)
			ft_childprocess(argv, envp, fd);
		waitpid(par, &status, 0);
		ft_parentprocess(argv, envp, fd);
	}
	else
		ft_error();
	return (0);
}
