/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 08:12:25 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 17:55:37 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "secret_walls.h"

void	secret_wall_erase(t_game *game, t_img *img)
{
	t_dlist		*lst;
	t_fpoint	pos;

	lst = game->secret_walls;
	while (lst)
	{
		pos = *(t_fpoint *)lst->content;
		sfe_pixel_fill(img,
			(t_area){{pos.x, pos.y},
		{pos.x + SPRITE_SIZE * 2, pos.y + SPRITE_SIZE * 2}},
			BACKGROUND_COL);
		lst = lst->next;
	}
}
