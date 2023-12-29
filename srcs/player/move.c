/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:04:27 by marykman          #+#    #+#             */
/*   Updated: 2023/12/30 00:04:58 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

t_bool	is_wall(t_game *game, t_fpoint pos)
{
	t_point	p_map;

	if (pos.x < 0 || pos.x > WIN_WIDTH
		|| pos.y < 0 || pos.y > WIN_HEIGHT)
		return (true);
	pos.x /= SPRITE_SIZE;
	pos.y /= SPRITE_SIZE;
	p_map = ft_fpoint_to_point(pos);
	if (game->map.tab[p_map.y][p_map.x] >= 1
		&& game->map.tab[p_map.y][p_map.x] <= 0x25)
		return (true);
	return (false);
}

t_bool	is_hitbox_colliding(t_game *game, t_fpoint pos)
{
	t_fpoint	points[4];
	size_t		i;

	points[0] = (t_fpoint){pos.x + game->player.hitbox.p1.x,
		pos.y + game->player.hitbox.p1.y};
	points[1] = (t_fpoint){pos.x + game->player.hitbox.p2.x,
		pos.y + game->player.hitbox.p1.y};
	points[2] = (t_fpoint){pos.x + game->player.hitbox.p2.x,
		pos.y + game->player.hitbox.p2.y};
	points[3] = (t_fpoint){pos.x + game->player.hitbox.p1.x,
		pos.y + game->player.hitbox.p2.y};
	i = -1;
	while (++i < 4)
		if (is_wall(game, points[i]))
			return (true);
	return (false);
}

void	player_move(t_game *game)
{
	t_fpoint	new;

	new = (t_fpoint){game->player.pos.x + game->player.spd.x,
		game->player.pos.y};
	if (!is_hitbox_colliding(game, new))
	{
		game->player.pos = new;
		game->player.on_wall = false;
	}
	else
	{
		game->player.spd.x = 0;
		game->player.on_wall = true;
	}
	new = (t_fpoint){game->player.pos.x,
		game->player.pos.y + game->player.spd.y};
	if (!is_hitbox_colliding(game, new))
	{
		game->player.pos = new;
		game->player.on_ground = false;
	}
	else
	{
		if (game->player.spd.y > 0)
			game->player.on_ground = true;
		game->player.spd.y = 0;
	}
}