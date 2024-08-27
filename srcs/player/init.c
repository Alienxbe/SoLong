/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:52:01 by marykman          #+#    #+#             */
/*   Updated: 2024/08/26 20:58:23 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int	player_init(t_player *player, t_point pos, t_img *assets)
{
	if (pos.x == -1 && pos.y == -1)
		return (0);
	player->pos = (t_fpoint){
		pos.x * SPRITE_SIZE,
		pos.y * SPRITE_SIZE - 5};
	player->hitbox = (t_area){{4, 12}, {28, 32}};
	player->direction = 1;
	player->frame = 0;
	player->assets = assets;
	player->spd = (t_fpoint){0};
	player->dash_time = 0;
	player->dash_target = (t_fpoint){0};
	if (player->max_djump <= 0)
		player->max_djump = PLAYER_MAX_DJUMP;
	player->djump = player->max_djump;
	player->steps = 0;
	return (1);
}
