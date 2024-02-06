/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:51:03 by marykman          #+#    #+#             */
/*   Updated: 2024/02/06 15:25:29 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "ft_math.h"
#include "sfe_color.h"
#include <stdio.h>

static void	player_update_states(t_game *game)
{
	game->player.input = (game->active_keys[GAME_KEY_RIGHT] * 1)
		+ (game->active_keys[GAME_KEY_LEFT] * (-1));
	game->player.on_ground = player_is_solid(game, (t_fpoint){0, 1});
	player_update_state_jump(game);
	player_update_state_jbuffer(game);
	player_update_state_grace(game);
	player_update_state_dash(game);
	// if (game->player.dash)
	// 	printf("Dash available\n");
	// printf("%d\n", game->player.djump);
}

void	player_update(t_game *game)
{
	printf("hair color: %x\n", sfe_color_get(game->assets + 0xf0, (t_point){16, 5}));
	if (game->player.djump)
	{
		for (int i = 0xf0; i < 0xff; i++)
			sfe_color_replace(game->assets + i, 0x3FF, 0xFF004D);
	}
	else
		for (int i = 0xf0; i < 0xff; i++)
			sfe_color_replace(game->assets + i, 0xFF004D, 0x3FF);
	player_update_states(game);
	player_update_speed(game);
	player_update_gravity(game);
	player_update_jump(game);
	player_update_wall_jump(game);
	player_update_dash(game);
	player_update_animation(game);
	player_move(game);
}
