/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:49:33 by marykman          #+#    #+#             */
/*   Updated: 2023/12/24 14:29:50 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "sfe_pixel.h"
#include "snowflakes.h"

void	snowflakes_draw(t_game *game, t_img img)
{
	size_t	i;

	i = -1;
	while (++i < SNOWFLAKE_COUNT)
		sfe_pixel_fill(img,
			(t_area){
				ft_fpoint_to_point(game->snowflakes[i].pos),
				{game->snowflakes[i].pos.x + game->snowflakes[i].size,
				game->snowflakes[i].pos.y + game->snowflakes[i].size}
			},
			0xFFFFFF);
}
