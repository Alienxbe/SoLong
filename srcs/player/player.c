/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:36:06 by marykman          #+#    #+#             */
/*   Updated: 2023/12/18 16:26:47 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "player.h"
#include "ft_printf.h"

int	player_init(t_player *player, t_point pos, t_img *assets)
{
	ft_printf("pos : %d | %d\n", pos.x, pos.y);
	if (pos.x == -1 && pos.y == -1)
		return (0);
	player->pos = (t_point){
		pos.x * SPRITE_SIZE,
		pos.y * SPRITE_SIZE};
	player->direction = 0;
	player->frame = 0;
	player->assets = assets;
	return (1);
}

void	player_draw(t_player *player, t_img *img)
{
	sfe_image_cpy(
		player->assets[0xf0],
		*img,
		player->pos);
}
