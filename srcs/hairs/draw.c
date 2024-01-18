/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:01:07 by marykman          #+#    #+#             */
/*   Updated: 2024/01/18 17:27:41 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_image.h"
#include "hairs.h"

void	hairs_draw(t_game *game, t_img *img)
{
	size_t	i;

	i = -1;
	while (++i < HAIR_COUNT)
		sfe_image_cpy(
			game->hairs[i].texture,
			img,
			ft_fpoint_to_point(game->hairs[i].pos)
			);
}
