/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:51:46 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/24 12:07:30 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "pipex.h"

/* Utils and Check */
int		ft_check_bonus(char *argv);
int		get_next_line(char **line);
/* Execution */
void	ft_here_doc(char *limiter);
void	ft_child_process(char *argv, char **envp);

#endif