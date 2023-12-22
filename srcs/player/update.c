/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:51:03 by marykman          #+#    #+#             */
/*   Updated: 2023/12/22 17:54:55 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "ft_math.h"
#include <stdio.h>

static float	abs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	player_update(t_game *game)
{
	t_point		input;
	float	accel;
	float	maxrun;
	float	decel;

	accel = 0.2;
	decel = 0.3;
	maxrun = 3;
	input.x = (game->active_keys[GAME_KEY_RIGHT] * 1)
		+ (game->active_keys[GAME_KEY_LEFT] * (-1));
	input.y = (game->active_keys[GAME_KEY_DOWN] * 1)
		+ (game->active_keys[GAME_KEY_UP] * (-1));
	if (input.x)
		game->player.spd.x += accel * input.x;
	else if (game->player.spd.x)
		game->player.spd.x -= decel * ((game->player.spd.x > 0) * 1 + (game->player.spd.x <= 0) * -1);
	if (input.y)
		game->player.spd.y += accel * input.y;
	else if (game->player.spd.y)
		game->player.spd.y -= decel * ((game->player.spd.y > 0) * 1 + (game->player.spd.y <= 0) * -1);

	if (abs(game->player.spd.x) > maxrun)
		game->player.spd.x = maxrun * input.x;
	if (abs(game->player.spd.y) > maxrun)
		game->player.spd.y = maxrun * input.y;
	// printf("speed: %f\n");
	game->player.direction = (game->player.spd.x < 0);
	player_move(game);
	// printf("%f\n", game->player.pos.x);
}
