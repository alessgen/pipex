/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:48:16 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/24 11:55:01 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
// # include "utils/get_next_line.h"

/* Utils and Check */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_print(char *string, ...);
char	**ft_split(char const *s, char c);
void	ft_clean_matrix(char **matrix);
void	ft_error(void);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
/* Execution */
char	*ft_pathfinder(char *cmd, char **envp);
void	ft_exec(char *argv, char **envp);
void	ft_childprocess(char **argv, char **envp, int *fd);
void	ft_parentprocess(char **argv, char **envp, int *fd);

#endif