/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:56:07 by marykman          #+#    #+#             */
/*   Updated: 2023/12/29 19:04:26 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_update_gravity(t_game *game)
{
	game->player.spd.y += GRAVITY;
	if (game->player.spd.y > FALL_SPEED_MAX)
		game->player.spd.y = FALL_SPEED_MAX;
}
