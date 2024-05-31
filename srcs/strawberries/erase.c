/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:23:48 by marykman          #+#    #+#             */
/*   Updated: 2024/05/31 14:47:30 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "strawberries.h"

void	strawberry_erase(t_game *game, t_img *img)
{
	t_list	*lst;
	t_fpoint	pos;

	lst = game->map.coin_pos;
	while (lst)
	{
		pos = *(t_fpoint *)lst->content;
		sfe_pixel_fill(img, (t_area){
			{pos.x, pos.y},
			{pos.x + SPRITE_SIZE, pos.y + SPRITE_SIZE}},
			BACKGROUND_COL);
		lst = lst->next;
	}
}
