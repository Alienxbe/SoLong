/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 08:03:11 by marykman          #+#    #+#             */
/*   Updated: 2024/06/14 08:25:57 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_image.h"
#include "secret_walls.h"

void	secret_wall_draw(t_game *game, t_img *img)
{
	t_dlist	*lst;
	size_t	i;

	lst = game->map.secret_walls;
	while (lst)
	{
		i = -1;
		while (++i < 4)
			sfe_image_cpy(
				game->assets + SECRET_WALLS_ASSET + i,
				img,
				add_point(ft_fpoint_to_point(*(t_fpoint *)lst->content),
				(t_point){i % 2 * SPRITE_SIZE, i / 2 * SPRITE_SIZE})
				);
		lst = lst->next;
	}
}
