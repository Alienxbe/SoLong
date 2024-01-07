/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:26:16 by marykman          #+#    #+#             */
/*   Updated: 2024/01/06 18:55:05 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "clouds.h"

void	clouds_erase(t_game *game, t_img *img)
{
	size_t	i;

	i = -1;
	while (++i < CLOUD_COUNT)
		sfe_pixel_fill(img,
			(t_area){game->clouds[i].pos, {
			game->clouds[i].pos.x + game->clouds[i].size.x,
			game->clouds[i].pos.y + game->clouds[i].size.y}},
			BACKGROUND_COL);
}
