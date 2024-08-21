/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:34:40 by marykman          #+#    #+#             */
/*   Updated: 2024/08/20 21:30:53 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "collisions.h"
#include <stdio.h>

static t_bool	is_wall_type(int block)
{
	return (block >= 1 && block <= 0x25);
}

t_bool	player_is_solid(t_game *game, t_fpoint pos)
{
	return (is_hitbox_colliding(
			&game->map,
			&is_wall_type, (t_fpoint)
			{game->player.pos.x + pos.x, game->player.pos.y + pos.y},
			game->player.hitbox)
			|| is_hitbox_colliding_secret_wall(&game->player, pos, game->secret_walls));
}

t_bool	player_is_oob(t_game *game, t_fpoint pos)
{
	float	p[2];

	p[0] = game->player.pos.x + game->player.hitbox.p1.x + pos.x;
	p[1] = game->player.pos.x + game->player.hitbox.p2.x + pos.x;
	return (p[0] <= 0 || p[1] >= WIN_WIDTH);
}
