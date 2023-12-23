/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:27:42 by marykman          #+#    #+#             */
/*   Updated: 2023/12/23 20:25:31 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_point.h"
# include "ft_area.h"
# include "events.h"

# define WIN_NAME		"So long but it's actually too long"
# define WIN_DIM		(16 * 2) * 16, (16 * 2) * 16
# define SPRITE_SIZE	32
# define MAPFILE_SUFFIX	".ber"

# define SPECIAL_CHAR	"PCE"

# define F_SPRITE_SHEET	"assets/CelestePico8.xpm"

typedef struct s_map
{
	int		**tab;
	t_point	player_pos;
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
	t_img		*assets;
}	t_player;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_img		*assets;
	t_keylist	active_keys;
}	t_game;

#endif
