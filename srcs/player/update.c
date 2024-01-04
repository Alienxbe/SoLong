/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:51:03 by marykman          #+#    #+#             */
/*   Updated: 2023/12/31 14:08:47 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "ft_math.h"
#include <stdio.h>


static void	player_update_states(t_game *game)
{
	game->player.input = (game->active_keys[GAME_KEY_RIGHT] * 1)
		+ (game->active_keys[GAME_KEY_LEFT] * (-1));
	game->player.on_ground = player_is_solid(game, (t_fpoint){0, 1});
	game->player.jump = game->active_keys[GAME_KEY_JUMP] && !game->player.p_jump;
	game->player.p_jump = game->active_keys[GAME_KEY_JUMP];
	if (game->player.jump)
		game->player.jbuffer = PLAYER_JUMP_BUFFER;
	else if (game->player.jbuffer > 0)
		game->player.jbuffer--;
	if (game->player.on_ground)
		game->player.grace = PLAYER_GRACE;
	else if (game->player.grace)
		game->player.grace--;
}

void	player_update(t_game *game)
{
	player_update_states(game);
	player_update_speed(game);
	player_update_gravity(game);
	player_update_jump(game);
	player_update_wall_jump(game);
	player_update_animation(game);
	player_move(game);
	// printf("%f\n", game->player.pos.x);
}
