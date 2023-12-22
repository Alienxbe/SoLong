/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:54:15 by marykman          #+#    #+#             */
/*   Updated: 2023/12/22 15:09:31 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	player_draw(t_player *player, t_img *img)
{
	sfe_image_mod_cpy(
		player->assets[0xf0 + player->frame],
		*img,
		ft_fpoint_to_point(player->pos),
		get_mod_function(player)
		);
}
