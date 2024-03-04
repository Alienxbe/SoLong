/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:51:03 by marykman          #+#    #+#             */
/*   Updated: 2024/03/04 18:16:23 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "ft_math.h"
#include "utils.h"
#include "sfe_color.h"
#include <stdio.h>

static void	player_set_hair_color(t_game *game, t_color actual, t_color next)
{
	size_t	i;

	if (actual == next)
		return ;
	i = 0xf0;
	while (i < 0xff)
		sfe_color_replace(game->assets + i++, actual, next);
}

static void	player_update_hair_color(t_game *game)
{
	t_color	actual;
	t_color	next;

	actual = sfe_color_get(game->assets + 0xf0, (t_point){5, 5});
	next = actual;
	if (actual == HAIR_COLOR_DASH_1 && game->player.djump == 0)
		next = HAIR_COLOR_DASH_0;
	else if (actual == HAIR_COLOR_DASH_0 && game->player.on_ground)
		next = HAIR_COLOR_DASH_1;
	player_set_hair_color(game, actual, next);
}

static void	player_update_states(t_game *game)
{
	game->player.input.x = (game->active_keys[GAME_KEY_RIGHT] * 1)
		+ (game->active_keys[GAME_KEY_LEFT] * (-1));
	game->player.input.y = (game->active_keys[GAME_KEY_DOWN] * 1)
		+ (game->active_keys[GAME_KEY_UP] * (-1));
	game->player.on_ground = player_is_solid(game, (t_fpoint){0, 1});
	player_update_state_jump(game);
	player_update_state_jbuffer(game);
	player_update_state_grace(game);
	player_update_state_dash(game);
}

void	player_update(t_game *game)
{
	player_update_states(game);
	if (game->player.dash_time > 0) // dash
	{
		game->player.dash_time--;
		game->player.spd.x = ft_appr(game->player.spd.x, game->player.dash_target.x, PLAYER_DASH_ACCEL);
		game->player.spd.y = ft_appr(game->player.spd.y, game->player.dash_target.y, PLAYER_DASH_ACCEL);
	}
	else
	{
		player_update_speed(game);
		player_update_gravity(game);
		player_update_jump(game);
		player_update_wall_jump(game);
		player_update_dash(game);
	}
	player_update_hair_color(game);
	player_update_animation(game);
	player_move(game);
}
