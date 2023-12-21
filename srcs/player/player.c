/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:36:06 by marykman          #+#    #+#             */
/*   Updated: 2023/12/20 21:56:23 by marykman         ###   ########.fr       */
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

static t_point	flip_x_mod(t_point img_src, t_point i)
{
	return ((t_point){img_src.x - i.x - 1, i.y});
}

static t_mod	get_mod_function(t_player *player)
{
	if (player->direction)
		return (&flip_x_mod);
	return (NULL);
}

void	player_draw(t_player *player, t_img *img)
{
	sfe_image_mod_cpy(
		player->assets[0xf0 + player->frame],
		*img,
		player->pos,
		get_mod_function(player)
		);
}
