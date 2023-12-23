/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:54:15 by marykman          #+#    #+#             */
/*   Updated: 2023/12/23 17:54:34 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "player.h"


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

// static t_point	crd_to_grid(t_fpoint p)
// {
// 	return ((t_point){p.x / SPRITE_SIZE, p.y / SPRITE_SIZE});
// }

// static t_point	grid_to_crd(t_point p)
// {
// 	return ((t_point){p.x * 32, p.y * 32});
// }

// static t_area	grid_to_area(t_point p)
// {
// 	t_point	crd;

// 	crd = grid_to_crd(p);
// 	return ((t_area){crd, {crd.x + 32, crd.y + 32}});
// }

void	player_draw(t_player *player, t_img *img)
{
	// t_point	player_tile = crd_to_grid((t_fpoint){player->pos.x + player->hitbox.p1.x, player->pos.y + player->hitbox.p1.y});
	// for (int y = -1; y < 2; y++)
	// 	for (int x = -1; x < 2; x++)
	// 		sfe_pixel_fill(*img, grid_to_area((t_point){player_tile.x - x, player_tile.y - y}), 0x00ff00);
	// sfe_pixel_fill(*img, grid_to_area(player_tile), 0x0000FF);
	sfe_image_mod_cpy(
		player->assets[0xf0 + player->frame],
		*img,
		ft_fpoint_to_point(player->pos),
		get_mod_function(player)
		);
}
