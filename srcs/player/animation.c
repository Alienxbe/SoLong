/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:08:07 by marykman          #+#    #+#             */
/*   Updated: 2023/12/30 00:27:34 by marykman         ###   ########.fr       */
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
			game->player.frame = 3;
	}
	else if (!game->player.spd.x)
		game->player.frame = 0;
	else
		game->player.frame = 1 + (int)spr_off%3;
	spr_off += 0.1;
	if (spr_off > 256)
		spr_off = 0;
}
