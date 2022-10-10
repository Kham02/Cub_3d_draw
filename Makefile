# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estrong <estrong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 19:00:53 by estrong           #+#    #+#              #
#    Updated: 2022/10/10 21:48:18 by estrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	main.c	start.c	draw_wall.c	raycast.c	init.c	

SRCS_B		= 

SRCS_DIR	= ./srcs/
SRCS_DIR_B	= ./srcs_b/

OBJS		= ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

OBJS_B		= ${addprefix ${SRCS_DIR_B}, ${SRCS_B:.c=.o}}

NAME		= cub3d

B_NAME		= cub3d_bonus

HEADER		= ./hdrs/cub3d.h
HEADER_B	= ./hdrs/cub3d.h

MLX_LIBS	= -lmlx -lm -L ./minilibx_opengl -framework OpenGL -framework AppKit

LIB			= ./libft/libft.a

CC = gcc
RM = rm -f

CFLAGS		= -Wall -Wextra -Werror

# COLORS

GREEN	= \033[0;32m
YELO	= \033[0;33m
BLUE	= \033[0;34m
NEW		= \033[0;35m
SHALLOW = \033[0m

# END COLORS

.PHONY: all clean fclean re bonus norm libft minilibx

all:		${NAME}

minilibx:	${MAKE} -C ./minilibx_opengl 2> /dev/null

%.o:%.c		${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

libft:		
			${MAKE} -C ./libft/

${NAME}:	${OBJS} ${HEADER}
			${MAKE} -C ./libft/
			${MAKE} -C ./minilibx_opengl 2> /dev/null
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB} ${MLX_LIBS}
	@echo "${GREEN}${NAME} compile!${SHALLOW}"

bonus:		${B_NAME}

${B_NAME}:	${OBJS_B} ${HEADER_B}
	@make -C ./libft/
	@make -C ./minilibx_opengl 2> /dev/null
	${CC} ${CFLAGS} -o ${B_NAME} ${OBJS_B} ${LIB} ${MLX_LIBS}
	@echo "${NEW}${B_NAME} compile!${SHALLOW}"

norm:
	@echo "${GREEN}|-----Chek NORMs!-----|${NEW}"
	@norminette ./srcs/
	@norminette ./cub3d.h
	@norminette ./libft/
	@echo "${GREEN}|-----Chek ended!-----|${SHALLOW}"

clean:		
	@${RM} ${OBJS} ${OBJS_B}
	@make clean -C ./libft/
	@make -C minilibx_opengl/ clean
	@echo "${BLUE}clean done!${SHALLOW}"

fclean:		
	@${RM} ${OBJS} ${OBJS_B} ${NAME} ${B_NAME}
	@make fclean -C ./libft/
	@make -C minilibx_opengl/ clean
	@echo "${YELO}fclean done!${SHALLOW}"

re:			fclean all