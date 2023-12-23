/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:13:52 by marykman          #+#    #+#             */
/*   Updated: 2023/12/23 23:20:53 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "clouds.h"

void	draw_clouds(t_game *game, t_img img)
{
	size_t	i;

	i = -1;
	while (++i < CLOUD_COUNT)
		sfe_pixel_fill(img,
			(t_area){game->clouds[i].pos, {game->clouds[i].pos.x + game->clouds[i].size.x, game->clouds[i].pos.y + game->clouds[i].size.y}},
			CLOUD_COL);
}
