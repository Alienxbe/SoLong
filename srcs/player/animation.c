/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:08:07 by marykman          #+#    #+#             */
/*   Updated: 2023/12/31 00:23:55 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_update_animation(t_game *game)
{
	static float	spr_off;

	if (game->player.spd.x < 0)
		game->player.direction = 1;
	if (game->player.spd.x > 0)
		game->player.direction = 0;
	if (!game->player.on_ground)
	{
		if (game->player.on_wall)
			game->player.frame = 4;
		else
			game->player.frame = 2;
	}
	else if (game->active_keys[GAME_KEY_DOWN])
		game->player.frame = 5;
	else if (game->active_keys[GAME_KEY_UP])
		game->player.frame = 6;
	else if (!game->player.spd.x)
		game->player.frame = 0;
	else
		game->player.frame = 1 + (int)spr_off%3;
	spr_off += 0.1;
}
