/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_jump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:10:50 by marykman          #+#    #+#             */
/*   Updated: 2023/12/29 19:16:43 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_update_wall_jump(t_game *game)
{
	if (game->active_keys[GAME_KEY_JUMP]
		&& game->player.on_wall
		&& !game->player.on_ground)
	{
		if (game->player.spd.x < 0)
			game->player.spd.x = WALL_JUMP_FORCE;
		else
			game->player.spd.x = -WALL_JUMP_FORCE;
		game->player.spd.y = -WALL_JUMP_FORCE;
	}
}
