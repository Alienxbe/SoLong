/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 02:54:27 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 03:17:47 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_image.h"
#include "utils.h"

void	draw_string(t_game *game, t_img *img, t_point pos, const char *s)
{
	int	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
	{
		sfe_image_cpy(game->alphabet + s[i], img, pos);
		pos.x += 16;
	}
}
