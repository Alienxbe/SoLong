/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:51:03 by marykman          #+#    #+#             */
/*   Updated: 2023/12/31 13:25:50 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "ft_math.h"
#include <stdio.h>



static void	player_update_states(t_game *game)
{
	game->player.on_ground = player_is_solid(game, (t_fpoint){0, 1});
}

void	player_update(t_game *game)
{
	int	input;

	input = (game->active_keys[GAME_KEY_RIGHT] * 1)
		+ (game->active_keys[GAME_KEY_LEFT] * (-1));
	player_update_states(game);
	player_update_speed(game, input);
	player_update_gravity(game, input);
	player_update_jump(game);
	player_update_wall_jump(game);
	player_update_animation(game);
	player_move(game);
	// printf("%f\n", game->player.pos.x);
}
