/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:09:41 by marykman          #+#    #+#             */
/*   Updated: 2024/01/25 14:28:49 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_update_state_jump(t_game *game)
{
	game->player.jump = game->active_keys[GAME_KEY_JUMP]
		&& !game->player.p_jump;
	game->player.p_jump = game->active_keys[GAME_KEY_JUMP];
}

void	player_update_state_jbuffer(t_game *game)
{
	if (game->player.jump)
		game->player.jbuffer = PLAYER_JUMP_BUFFER;
	else if (game->player.jbuffer > 0)
		game->player.jbuffer--;
}

void	player_update_state_grace(t_game *game)
{
	if (game->player.on_ground)
	{
		game->player.grace = PLAYER_GRACE;
		if (game->player.djump < game->player.max_djump)
			game->player.djump = game->player.max_djump;
	}
	else if (game->player.grace)
		game->player.grace--;
}

void	player_update_state_dash(t_game *game)
{
	game->player.dash = game->active_keys[GAME_KEY_DASH]
		&& !game->player.p_dash;
	game->player.p_dash = game->active_keys[GAME_KEY_DASH];
}
