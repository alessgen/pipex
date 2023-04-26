# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 12:08:07 by agenoves          #+#    #+#              #
#    Updated: 2022/03/24 12:37:12 by agenoves         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 					pipex
NAME_BONUS =			pipex_bonus

CC = 					gcc
CFLAGS = 				-Wall -Werror -Wextra
RM = 					rm -f

FILES = 				ft_pipex \
						ft_utils \
						utils/ft_print \
						utils/ft_split \
						utils/ft_strjoin \
						utils/ft_strlen 
						
FILES_BONUS =			ft_pipex_bonus \
						ft_utils \
						utils/ft_print \
						utils/ft_split \
						utils/ft_strjoin \
						utils/ft_strlen

		
SRCS_DIR = 				./
SRCS = 					$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS = 					${SRCS:.c=.o}

SRCS_DIR_BONUS = 		./
SRCS_BONUS = 			$(addprefix $(SRCS_DIR_BONUS), $(addsuffix .c, $(FILES_BONUS)))
OBJS_BONUS = 			${SRCS_BONUS:.c=.o}

${NAME}:
	${CC} ${CFLAGS} ${SRCS} -o $@
	
${NAME_BONUS}:
	${CC} ${CFLAGS} ${SRCS_BONUS} -o $@

all: ${NAME} 
${NAME}: ${OBJS}

bonus: ${NAME_BONUS}
${NAME_BONUS}: ${OBJS_BONUS}

clean: 
	@${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	@${RM} ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re
