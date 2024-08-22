/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:21:03 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 17:51:07 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strawberries.h"
#include "secret_walls.h"
#include "collisions.h"
#include "player.h"

static t_bool	player_in_void(t_game *game)
{
	return (game->player.pos.y + game->player.hitbox.p1.y
		>= game->map.pixel_size.y - 1);
}

t_bool	player_isdead(t_game *game)
{
	return (is_hitbox_colliding_spikes(game)
		|| player_in_void(game));
}

void	player_death(t_game *game)
{
	player_init(&game->player, game->map.player_pos, game->assets);
	strawberry_init(game);
	secret_wall_init(game);
}
