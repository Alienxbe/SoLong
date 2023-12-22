/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:04:27 by marykman          #+#    #+#             */
/*   Updated: 2023/12/22 16:55:27 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

typedef enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_direction;

t_bool	is_wall(t_game *game, t_fpoint pos)
{
	t_point	p_map;

	pos.x /= SPRITE_SIZE;
	pos.y /= SPRITE_SIZE;
	p_map = ft_fpoint_to_point(pos);
	if (game->map.tab[p_map.y][p_map.x] >= 1 && game->map.tab[p_map.y][p_map.x] <= 0x25)
		return (true);
	return (false);
}

t_bool	is_hitbox_colliding(t_game *game, t_fpoint pos)
{
	t_fpoint	points[4];

	points[0] = (t_fpoint){pos.x + game->player.hitbox.p1.x,
					pos.y + game->player.hitbox.p1.y};
	points[1] = (t_fpoint){pos.x + game->player.hitbox.p2.x,
					pos.y + game->player.hitbox.p1.y};
	points[2] = (t_fpoint){pos.x + game->player.hitbox.p2.x,
					pos.y + game->player.hitbox.p2.y};
	points[3] = (t_fpoint){pos.x + game->player.hitbox.p1.x,
					pos.y + game->player.hitbox.p2.y};
	for (int i = 0; i < 4; i++)
		if (is_wall(game, points[i]))
			return (true);
	return (false);
}

t_bool	is_colliding(t_game *game, t_fpoint pos, t_direction d)
{
	if (d == WEST && (pos.x + game->player.hitbox.p1.x < 0))
		return (true);
	else if (d == EAST && pos.x + game->player.hitbox.p2.x > game->map.size.x * SPRITE_SIZE)
		return (true);
	else if (d == NORTH && pos.y + game->player.hitbox.p1.y < 0)
		return (true);
	else if (d == SOUTH && pos.y + game->player.hitbox.p2.y > game->map.size.y * SPRITE_SIZE)
		return (true);
	return (false);
}

void	player_move(t_game *game)
{
	t_fpoint	new;

	new = (t_fpoint){game->player.pos.x + game->player.spd.x,
			game->player.pos.y + game->player.spd.y};
	if (is_colliding(game, new, WEST) || is_colliding(game, new, EAST))
	{
		new.x = game->player.pos.x;
		game->player.spd.x = 0;
	}
	if (is_colliding(game, new, NORTH) || is_colliding(game, new, SOUTH))
	{
		new.y = game->player.pos.y;
		game->player.spd.y = 0;
	}
	if (!is_hitbox_colliding(game, new))
		game->player.pos = 
	game->player.pos = new;
}