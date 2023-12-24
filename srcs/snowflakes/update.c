/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:53:40 by marykman          #+#    #+#             */
/*   Updated: 2023/12/24 14:44:28 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "sfe_pixel.h"
#include "snowflakes.h"

static void	erase_snowflake(t_game *game, t_img img, size_t i)
{
	sfe_pixel_fill(img,
			(t_area){
				ft_fpoint_to_point(game->snowflakes[i].pos),
				{game->snowflakes[i].pos.x + game->snowflakes[i].size,
				game->snowflakes[i].pos.y + game->snowflakes[i].size}
			},
			0x0);
}

void	snowflakes_update(t_game *game, t_img img)
{
	size_t	i;

	i = -1;
	while (++i < SNOWFLAKE_COUNT)
	{
		erase_snowflake(game, img, i);
		game->snowflakes[i].pos.x += (float)game->snowflakes[i].speed;
		game->snowflakes[i].pos.y += game->snowflakes[i].ampl * sin(
									game->snowflakes[i].frq
									* game->snowflakes[i].pos.x);
		if (game->snowflakes[i].pos.x > WIN_WIDTH)
			game->snowflakes[i] = random_snowflake(0);
	}
}
