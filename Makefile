# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marykman <marykman@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 20:20:08 by marykman          #+#    #+#              #
#    Updated: 2024/08/23 18:19:15 by marykman         ###   ########.fr        #
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
	DFLAGS			:=	-D LINUX
else ifeq ($(detected_OS), Darwin)
	MLXFLAGS		:=	-framework OpenGL -framework AppKit
	MLX_FOLDER		:=	libs/minilibx_opengl
	DFLAGS			:=	-D MACOS
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
NAME_BONUS			:=	so_long_bonus

FILES				:=	main.c
FILES_EVENTS		:=	convert.c \
						events.c
FILES_MAIN_SCENE	:=	destroy.c \
						init.c \
						update.c \
						draw.c \
						erase.c
FILES_STATS_BAR		:=	draw.c
FILES_PARSING		:=	set_exit.c \
						set_player.c \
						parse_content.c \
						parse_map.c \
						check_map.c \
						check_path.c \
						fill_tmp_map.c \
						parsing.c
FILES_COLLISIONS	:=	is_hitbox_colliding.c \
						is_hitbox_colliding_spikes.c \
						is_hitbox_colliding_secret_wall.c \
						is_type.c \
						is_wall.c
FILES_COINS			:=	add.c \
						remove.c
FILES_PLAYER		:=	init.c \
						draw.c \
						erase.c \
						update.c \
						state.c \
						move.c \
						animation.c \
						collisions.c \
						speed.c \
						gravity.c \
						jump.c \
						dash.c \
						wall_jump.c \
						death.c
FILES_EXIT			:=	init.c \
						draw.c \
						erase.c \
						update.c
FILES_CLOUDS		:=	init.c \
						draw.c \
						erase.c \
						update.c \
						new_random.c
FILES_SNOWFLAKES	:=	init.c \
						draw.c \
						erase.c \
						update.c \
						new_random.c
FILES_STRAWBERRIES	:=	init.c\
						draw.c \
						erase.c \
						update.c
FILES_SECRET_WALLS	:=	init.c\
						draw.c \
						erase.c \
						update.c
FILES_UTILS			:=	ft_appr.c \
						ft_abs.c \
						pixel_to_map_pos.c \
						draw_string.c \
						free_tab.c

SRCS				:=	$(addprefix srcs/, ${FILES})
SRCS				+=	$(addprefix srcs/events/, ${FILES_EVENTS})
SRCS				+=	$(addprefix srcs/main_scene/, ${FILES_MAIN_SCENE})
SRCS				+=	$(addprefix srcs/stats_bar/, ${FILES_STATS_BAR})
SRCS				+=	$(addprefix srcs/parsing/, ${FILES_PARSING})
SRCS				+=	$(addprefix srcs/collisions/, ${FILES_COLLISIONS})
SRCS				+=	$(addprefix srcs/coins/, ${FILES_COINS})
SRCS				+=	$(addprefix srcs/player/, ${FILES_PLAYER})
SRCS				+=	$(addprefix srcs/exit/, ${FILES_EXIT})
SRCS				+=	$(addprefix srcs/clouds/, ${FILES_CLOUDS})
SRCS				+=	$(addprefix srcs/snowflakes/, ${FILES_SNOWFLAKES})
SRCS				+=	$(addprefix srcs/strawberries/, ${FILES_STRAWBERRIES})
SRCS				+=	$(addprefix srcs/secret_walls/, ${FILES_SECRET_WALLS})
SRCS				+=	$(addprefix srcs/utils/, ${FILES_UTILS})
OBJS				:=	$(patsubst srcs%.c, objs%.o, ${SRCS})

# header files
FILES				:=	clouds.h \
						collisions.h \
						coins.h \
						errors.h \
						events.h \
						exit.h \
						parsing.h \
						player.h \
						sc_main.h \
						secret_walls.h \
						snowflakes.h \
						so_long.h \
						stats_bar.h \
						utils.h
HEADERS				:=	$(addprefix includes/, ${FILES});

# -----------------------------------Rules-------------------------------------

objs/%.o:	srcs/%.c ${HEADERS}
	${CC} ${CFLAGS} ${DFLAGS} ${INCLUDES} -c $< -o $@
	@echo "${PREFIX}Compilation of $<..."
	

$(NAME):	clean ${FT} ${MLX} ${SFE} ${OBJS} ${HEADERS}
	${CC} ${CFLAGS} ${DFLAGS} ${OBJS} ${LIBRARIES} ${MLXFLAGS} -o $@
	@echo "${PREFIX}${NAME} compiled!"

$(FT):
	${MAKE_FT}

$(MLX):
	${MAKE_MLX}

$(SFE):
	${MAKE_SFE} LIBFT_FOLDER=${CURRENT_FOLDER}/${FT_FOLDER} \
				MLX_FOLDER=${CURRENT_FOLDER}/${MLX_FOLDER}

all:	${NAME}

bonus:	NAME = ${NAME_BONUS}
bonus:	DFLAGS += -D BONUS
bonus:	${NAME}

clean:
	${MAKE_FT} clean
	${MAKE_MLX} clean
	${MAKE_SFE} clean
	@rm -f ${OBJS}

fclean:
	${MAKE_FT} fclean
	${MAKE_MLX} clean
	${MAKE_SFE} fclean
	@rm -f ${NAME} ${NAME_BONUS} ${OBJS}

re:		fclean all

# -----------------------------------.PHONY------------------------------------

.PHONY:	all clean fclean re bonus
