/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:42:43 by agenoves          #+#    #+#             */
/*   Updated: 2022/09/22 00:26:06 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* Get next line */
int	ft_get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}

/* Questa funzione controlla se, qualora venissero passati piu di 5 argomenti,
il primo argomento (argv[1]) é "here_doc". */
int	ft_check_bonus(char *argv)
{
	int	i;

	i = 0;
	if (argv == NULL)
		return (0);
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'c' && argv[i - 1] == 'o' && argv[i - 2] == 'd' \
		&& argv[i - 3] == '_' && argv[i - 4] == 'e' && argv[i - 5] == 'r' \
		&& argv[i - 6] == 'e' && argv[i - 7] == 'h')
		return (1);
	return (0);
}

/* Processo figlio che esegue un pipe e un fork, inserisce l'output in un pipe,
e chiude con una funzione di esecuzione */
void	ft_child_process(char *argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		ft_exec(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
	}
}

/* Funzione che prende come parametri il limiter (argv[2]) e controlla, con 
get_next_line dallo stdin se appare la stringa limiter, confrontandola
con strncmp e, inserisce l'output all'interno di una pipe */
void	ft_here_doc(char *limiter)
{
	int		fd[2];
	char	*line;
	pid_t	r;

	if (pipe(fd) == -1)
		ft_error();
	r = fork();
	if (r == 0)
	{
		close(fd[0]);
		while (ft_get_next_line(&line))
		{
			if (ft_strncmp(limiter, line, ft_strlen(limiter)) == 0)
				exit(0);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fileout;
	int	filein;
	int	i;	

	if (argc >= 5)
	{
		if (ft_check_bonus(argv[1]))
		{
			i = 3;
			fileout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
			ft_here_doc(argv[2]);
		}
		else
		{
			i = 2;
			filein = open(argv[1], O_RDONLY, 0777);
			fileout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			dup2(filein, 0);
		}
		while (i < argc - 2)
			ft_child_process(argv[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		ft_exec(argv[argc - 2], envp);
	}
	ft_error();
}
