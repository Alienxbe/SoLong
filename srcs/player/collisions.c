/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:34:40 by marykman          #+#    #+#             */
/*   Updated: 2023/12/31 13:25:59 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

t_bool	is_hitbox_colliding(t_game *game, t_fpoint pos, t_area hitbox)
{
	t_fpoint	points[4];
	size_t		i;

	points[0] = (t_fpoint){pos.x + hitbox.p1.x,
		pos.y + hitbox.p1.y};
	points[1] = (t_fpoint){pos.x + hitbox.p2.x,
		pos.y + hitbox.p1.y};
	points[2] = (t_fpoint){pos.x + hitbox.p2.x,
		pos.y + hitbox.p2.y};
	points[3] = (t_fpoint){pos.x + hitbox.p1.x,
		pos.y + hitbox.p2.y};
	i = -1;
	while (++i < 4)
		if (is_wall(game, points[i]))
			return (true);
	return (false);
}

t_bool	player_is_solid(t_game *game, t_fpoint pos)
{
	return (is_hitbox_colliding(game, (t_fpoint)
		{game->player.pos.x + pos.x, game->player.pos.y + pos.y},
		game->player.hitbox));
}
