/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:32:03 by marykman          #+#    #+#             */
/*   Updated: 2023/12/31 13:56:03 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "player.h"

static float	get_gravity(t_game *game)
{
	if (game->player.input
		&& player_is_solid(game, (t_fpoint){game->player.input, 0}))
		return (PLAYER_WALLSLIDE_MAX);
	return (PLAYER_GRAVITY_MAX);
}

void	player_update_gravity(t_game *game)
{
	float	gravity;
	float	maxfall;

	if (game->player.on_ground)
		return ;
	gravity = PLAYER_GRAVITY_ACCEL;
	if (ft_abs(game->player.spd.y) <= 0.3)
		gravity *= 0.3;
	maxfall = get_gravity(game);
	game->player.spd.y = ft_appr(game->player.spd.y, maxfall, gravity);
}
