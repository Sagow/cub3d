SRCS		=	file_processing/file_processing.c	\
				file_processing/file_processing2.c	\
				file_processing/fp_colors.c			\
				file_processing/fp_map.c			\
				file_processing/fp_map2.c			\
				file_processing/fp_resolution.c		\
				file_processing/fp_sprite.c			\
				file_processing/fp_walls.c			\
				close.c								\
				detect_wall.c						\
				detect_wall2.c						\
				draw_aerial.c						\
				drawing.c							\
				drawing2.c							\
				errors.c							\
				init_cub3d.c						\
				main.c								\
				mathematics.c						\
				move.c								\
				save.c								\
				sprite.c							\
				get_next_line/get_next_line.c		\
				get_next_line/get_next_line_utils.c
INCLUDES	=	-Iget_next_line						\
				-Ilibftprintf						\
				-Iminilibx-linux					\
				-Iincludes
OBJS		=	${SRCS:.c=.o}
CC			=	@clang
RM			=	@rm -f
FLAGS		=	-Wall -Werror -Wextra ${INCLUDES} -D BUFFER_SIZE=4096 \
				-fsanitize=address -g
LIBS		=	-Lminilibx-linux -lXext -lbsd -lmlx -lX11 -lm -g
NAME		=	Cub3D

.c.o :
			${CC} -c $< -o ${<:.c=.o} ${FLAGS}

$(NAME) :	start ${OBJS}
			@echo "\033[0;34mCompiling minilibx-linux\033[0m"
			@make -s -C minilibx-linux -f Makefile
			@echo "\033[0;34mCompiling libftprintf\033[0m"
			@make -s -C libftprintf -f Makefile
			@echo "\033[0;34mCompiling sources\033[0m"
			${CC} ${OBJS} $(LIBS) -o ${NAME} ${FLAGS} -L. \
			libftprintf/libftprintf.a
			@echo "\033[1;34mDone\033[0m"

all :		${NAME}

bonus :		all

clean :
			@echo "\033[0;34mErasing the .o\033[0m"
			@make clean -s -C libftprintf -f Makefile
			@make clean -s -C minilibx-linux -f Makefile
			${RM} ${OBJS}

fclean :	clean
			@echo "\033[0;34mErasing the .a\033[0m"
			@make fclean -s -C libftprintf -f Makefile
			${RM} ${NAME}

re:			fclean all

start :
			@echo "\033[1;34mMaking Cub3d\033[0m"

.PHONY:		all fclean clean re start