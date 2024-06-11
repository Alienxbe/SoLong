/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:27:42 by marykman          #+#    #+#             */
/*   Updated: 2024/06/11 15:47:02 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include "ft_dlist.h"
# include "ft_point.h"
# include "ft_area.h"
# include "ft_list.h"
# include "events.h"

# define WIN_NAME		"So long but it's actually too long"
# define WIN_DIM		(16 * 2) * 16, (16 * 2) * 16
# define WIN_HEIGHT		32 * 16
# define WIN_WIDTH		32 * 16
# define SPRITE_SIZE	32
# define BACKGROUND_COL	0x0
# define MAPFILE_SUFFIX	".ber"

# define CLOUD_COUNT		16
# define SNOWFLAKE_COUNT	24
# define HAIR_COUNT			3
# define HAIR_COLOR_DASH_1	0xFF004D
# define HAIR_COLOR_DASH_0	0x29ADFF

# define SPECIAL_CHAR	"PCEB"

# define F_SPRITE_SHEET	"assets/CelestePico8.xpm"

typedef struct s_map
{
	int		**tab;
	t_point	player_pos;
	t_dlist	*coin_pos;
	t_point	size;
}	t_map;

typedef struct s_player
{
	t_fpoint	pos;
	t_fpoint	spd;
	t_area		hitbox;
	t_bool		on_ground;
	t_bool		on_wall;
	int			frame;
	int			direction;
	t_bool		p_jump;
	t_bool		jump;
	int			jbuffer;
	int			grace;
	t_bool		p_dash;
	t_bool		dash;
	int			djump;
	int			max_djump;
	int			dash_time;
	t_fpoint	dash_target;
	t_point		input;
	t_img		*assets;
}	t_player;

typedef struct s_cloud
{
	t_point	pos;
	size_t	speed;
	t_point	size;
}	t_cloud;

typedef struct s_snowflake
{
	t_fpoint	pos;
	size_t		size;
	size_t		speed;
	float		frq;
	size_t		ampl;
}	t_snowflake;

typedef struct s_smoke
{
	t_fpoint	pos;
	t_point		speed;
	t_point		flip;
	size_t		frame;
	t_img		*assets;
	t_dlist		*elem;
}	t_smoke;

typedef struct s_hair
{
	t_fpoint	pos;
	t_img		*texture;
}	t_hair;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_cloud		clouds[CLOUD_COUNT];
	t_snowflake	snowflakes[SNOWFLAKE_COUNT];
	t_hair		hairs[HAIR_COUNT];
	t_dlist		*smokes;
	t_img		*assets;
	t_keylist	active_keys;
	int			move_count;
}	t_game;

#endif
