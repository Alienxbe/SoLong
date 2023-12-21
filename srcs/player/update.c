/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:51:03 by marykman          #+#    #+#             */
/*   Updated: 2023/12/21 20:08:24 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_update(t_game *game)
{
	float	accel;
	float	maxrun;
	float	decel;

	accel = 0.7;
	decel = 0.7;
	maxrun = 3;
	if (game->active_keys[GAME_KEY_RIGHT])
		game->player.spd += accel;
	else
		game->player.spd -= decel;
	if (game->player.spd > maxrun)
		game->player.spd = maxrun;
	else if (game->player.spd < 0)
		game->player.spd = 0;
	// printf("speed: %f\n");
	game->player.pos.x += (int)game->player.spd;
}
