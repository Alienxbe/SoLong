/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:50:15 by marykman          #+#    #+#             */
/*   Updated: 2023/12/31 00:30:27 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "utils.h"
#include "player.h"

static float	get_player_state_accel(t_game *game)
{
	if (game->player.on_ground)
		return (PLAYER_MOVE_GROUND_ACCEL);
	return (PLAYER_MOVE_AIR_ACCEL);
}

void	player_update_speed(t_game *game, int input)
{
	if (ft_abs(game->player.spd.x) > PLAYER_MOVE_MAX)
		game->player.spd.x = ft_appr(
				game->player.spd.x,
				ft_signfloat(game->player.spd.x) * PLAYER_MOVE_MAX,
				PLAYER_MOVE_DECEL);
	else
		game->player.spd.x = ft_appr(
				game->player.spd.x,
				input * PLAYER_MOVE_MAX,
				get_player_state_accel(game));
}
