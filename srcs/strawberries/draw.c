/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:04:41 by marykman          #+#    #+#             */
/*   Updated: 2024/06/14 19:17:27 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_image.h"
#include "strawberries.h"

void	strawberry_draw(t_game *game, t_img *img)
{
	t_dlist	*lst;

	lst = game->map.strawberries;
	while (lst)
	{
		sfe_image_cpy(
			game->assets + STRAWBERRY_ASSET,
			img,
			ft_fpoint_to_point(*(t_fpoint *)lst->content)
			);
		lst = lst->next;
	}
}
