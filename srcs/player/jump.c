/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:07:57 by marykman          #+#    #+#             */
/*   Updated: 2023/12/29 19:09:20 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_update_jump(t_game *game)
{
	if (game->active_keys[GAME_KEY_JUMP] && game->player.on_ground)
		game->player.spd.y = -JUMP_FORCE;
}
