/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:04:03 by marykman          #+#    #+#             */
/*   Updated: 2024/01/05 21:01:56 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "snowflakes.h"

void	snowflakes_erase(t_game *game, t_img img)
{
	size_t	i;

	i = -1;
	while (++i < SNOWFLAKE_COUNT)
		sfe_pixel_fill(img,
			(t_area){ft_fpoint_to_point(game->snowflakes[i].pos), {
			game->snowflakes[i].pos.x + game->snowflakes[i].size,
			game->snowflakes[i].pos.y + game->snowflakes[i].size}},
			BACKGROUND_COL);
}
