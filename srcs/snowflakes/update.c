/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:53:40 by marykman          #+#    #+#             */
/*   Updated: 2024/08/21 16:41:23 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "sfe_pixel.h"
#include "snowflakes.h"

void	snowflakes_update(t_game *game)
{
	size_t	i;

	i = -1;
	while (++i < SNOWFLAKE_COUNT)
	{
		game->snowflakes[i].pos.x += (float)game->snowflakes[i].speed;
		game->snowflakes[i].pos.y += game->snowflakes[i].ampl * sin(
				game->snowflakes[i].frq
				* game->snowflakes[i].pos.x);
		if (game->snowflakes[i].pos.x > game->map.pixel_size.x)
			game->snowflakes[i] = snowflake_new_random(0);
	}
}
