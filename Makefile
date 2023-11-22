# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marykman <marykman@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 20:20:08 by marykman          #+#    #+#              #
#    Updated: 2023/11/22 22:41:01 by marykman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -----------------------------------Colors------------------------------------

RED				:=	[38;5;9m
GREEN			:=	[38;5;10m
BLUE			:= 	[38;5;14m
YELLOW			:=	[38;5;226m
RESET			:=	[38;5;7m
PREFIX			=	[${YELLOW}${NAME}${RESET}]		

# ------------------------------------VARS-------------------------------------

CURRENT_FOLDER		:=	$(shell pwd)

ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell uname)
endif

# ---------------------------------Compilation---------------------------------

CC					:=	@gcc
CFLAGS				:=	-Wall -Wextra -Werror

ifeq ($(detected_OS), Linux)
	MLXFLAGS		:=	-lXext -lX11 -lm -lz
	MLX_FOLDER		:=	libs/minilibx-linux
else ifeq ($(detected_OS), Darwin)
	MLXFLAGS		:=	-framework OpenGL -framework AppKit
	MLX_FOLDER		:=	libs/minilibx_opengl
endif

# ---------------------------------Librairies----------------------------------

FT_FOLDER			:=	libs/libft
SFE_FOLDER			:=	libs/SnowFlakeEngine

FT					:=	${FT_FOLDER}/libft.a
MLX					:=	${MLX_FOLDER}/libmlx.a
SFE					:=	${SFE_FOLDER}/libsfe.a

MAKE_FT				:=	@make -s -C ${FT_FOLDER}
MAKE_MLX			:=	@make -s -C ${MLX_FOLDER}
MAKE_SFE			:=	@make -s -C ${SFE_FOLDER}

INCLUDES			:=	-I ${MLX_FOLDER} \
						-I ${FT_FOLDER}/includes \
						-I ${SFE_FOLDER}/includes \
						-I ./includes
LIBRARIES			:=	-L./${SFE_FOLDER} -lsfe \
						-L./${FT_FOLDER} -lft \
						-L./${MLX_FOLDER} -lmlx

# --------------------------------Source files---------------------------------

NAME				:=	so_long
FILES				:=	main.c \
						sc_main.c \
						sfe_load_sprite_sheet.c
SRCS				:=	$(addprefix srcs/, ${FILES})
OBJS				:=	$(addprefix objs/, ${FILES:.c=.o})
FILES				:=	so_long.h \
						sc_main.h
HEADERS				:=	$(addprefix includes/, ${FILES});

# -----------------------------------Rules-------------------------------------

objs/%.o:	srcs/%.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
	@echo "${PREFIX}Compilation of $<..."
	

$(NAME):	${FT} ${MLX} ${SFE} ${OBJS} ${HEADERS}
	${CC} ${CFLAGS} ${OBJS} ${LIBRARIES} ${MLXFLAGS} -o $@
	@echo "${PREFIX}${NAME} compiled!"

$(FT):
	${MAKE_FT}

$(MLX):
	${MAKE_MLX}

$(SFE):
	${MAKE_SFE} LIBFT_FOLDER=${CURRENT_FOLDER}/${FT_FOLDER} \
				MLX_FOLDER=${CURRENT_FOLDER}/${MLX_FOLDER}

all:	${NAME}

clean:
	${MAKE_FT} clean
	${MAKE_MLX} clean
	${MAKE_SFE} clean
	@rm -f ${OBJS}

fclean:
	${MAKE_FT} fclean
	${MAKE_MLX} clean
	${MAKE_SFE} fclean
	@rm -f ${NAME} ${OBJS}

re:		fclean all

# -----------------------------------.PHONY------------------------------------

.PHONY:	all clean fclean re
