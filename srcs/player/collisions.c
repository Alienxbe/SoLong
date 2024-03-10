/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:34:40 by marykman          #+#    #+#             */
/*   Updated: 2024/03/05 13:39:16 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "collisions.h"
#include <stdio.h>

static t_bool	is_wall_type(int block)
{
	return (block >= 1 && block <= 0x25);
}

static t_bool	is_oob(int block)
{
	return (block == -1);
}

t_bool	player_is_solid(t_game *game, t_fpoint pos)
{
	return (is_hitbox_colliding(
			&game->map,
			&is_wall_type, (t_fpoint)
			{game->player.pos.x + pos.x, game->player.pos.y + pos.y},
			game->player.hitbox));
}

t_bool	player_is_oob(t_game *game, t_fpoint pos)
{
	return (is_hitbox_colliding(&game->map, &is_oob, (t_fpoint)
			{game->player.pos.x + pos.x, game->player.pos.y + pos.y},
			game->player.hitbox));
}
