/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:14:16 by marykman          #+#    #+#             */
/*   Updated: 2023/12/23 23:21:03 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "clouds.h"

static void	erase_cloud(t_game *game, t_img img, size_t i)
{
	sfe_pixel_fill(img, (t_area){game->clouds[i].pos,
			{game->clouds[i].pos.x + game->clouds[i].size.x,
			game->clouds[i].pos.y + game->clouds[i].size.y}}, 0x0);
}

void	update_clouds(t_game *game, t_img img)
{
	size_t	i;

	i = -1;
	while (++i < CLOUD_COUNT)
	{
		erase_cloud(game, img, i);
		game->clouds[i].pos.x += game->clouds[i].speed;
		if (game->clouds[i].pos.x > WIN_WIDTH)
			game->clouds[i] = random_cloud(-150);
	}
}
