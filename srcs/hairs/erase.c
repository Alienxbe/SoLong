/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:30:29 by marykman          #+#    #+#             */
/*   Updated: 2024/01/18 17:33:39 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "hairs.h"

void	hairs_erase(t_game *game, t_img *img)
{
	size_t	i;

	i = -1;
	while (++i < HAIR_COUNT)
		sfe_pixel_fill(img, (t_area){{
			game->hairs[i].pos.x, game->hairs[i].pos.y}, {
			game->hairs[i].pos.x + SPRITE_SIZE, game->hairs[i].pos.y + SPRITE_SIZE}},
			BACKGROUND_COL);
}
