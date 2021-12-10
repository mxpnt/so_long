# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 10:09:35 by mapontil          #+#    #+#              #
#    Updated: 2021/12/09 09:54:58 by mapontil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	so_long.c \
			parsing.c \
			error.c \
			error_msg.c \
			print.c \
			print_player.c \
			movement.c \
			utils.c \
			get_next_line.c \
			get_next_line_utils.c 
OBJS	=	$(addprefix srcs/, ${SRCS:.c=.o})
HEAD	=	includes/so_long.h \
			includes/get_next_line.h
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	so_long

%.o:		%.c ${HEAD}
			${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			make -C mlx
			${CC} ${CFLAGS} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
all:		${NAME}
clean:
			make clean -C mlx
			rm -f ${OBJS}
fclean:		clean
			rm -f ${NAME}
re:			fclean all
.PHONY:		all clean fclean re