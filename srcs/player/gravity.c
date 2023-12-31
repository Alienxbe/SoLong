/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:32:03 by marykman          #+#    #+#             */
/*   Updated: 2023/12/31 13:28:17 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "player.h"

static float	wall_slide(t_game *game, int input)
{
	if (input && game->player.on_wall)
		return (PLAYER_WALLSLIDE_MAX);
	return (PLAYER_GRAVITY_MAX);
}

void	player_update_gravity(t_game *game, int input)
{
	float	gravity;
	float	maxfall;

	if (game->player.on_ground)
		return ;
	gravity = PLAYER_GRAVITY_ACCEL;
	maxfall = PLAYER_GRAVITY_MAX;
	if (ft_abs(game->player.spd.y) <= 0.3)
		gravity *= 0.3;
	maxfall = wall_slide(game, input);
	game->player.spd.y = ft_appr(game->player.spd.y, maxfall, gravity);
}
