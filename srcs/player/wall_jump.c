/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_jump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:10:50 by marykman          #+#    #+#             */
/*   Updated: 2023/12/31 13:32:20 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static int	get_wall_dir(t_game *game)
{
	if (player_is_solid(game, (t_fpoint){1, 0}))
		return (1);
	if (player_is_solid(game, (t_fpoint){-1, 0}))
		return (-1);
	return (0);
}

void	player_update_wall_jump(t_game *game)
{
	int	wall_dir;

	wall_dir = get_wall_dir(game);
	if (game->active_keys[GAME_KEY_JUMP]
		&& wall_dir != 0
		&& !game->player.on_ground)
	{

		game->player.spd.x = -WALL_JUMP_FORCE * wall_dir;
		game->player.spd.y = -WALL_JUMP_FORCE + 1;
	}
}
