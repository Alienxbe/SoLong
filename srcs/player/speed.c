/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:50:15 by marykman          #+#    #+#             */
/*   Updated: 2023/12/30 00:02:20 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "utils.h"
#include "player.h"

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
				PLAYER_MOVE_GROUND_ACCEL);
}
