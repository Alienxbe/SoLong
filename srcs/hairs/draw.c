/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:01:07 by marykman          #+#    #+#             */
/*   Updated: 2024/01/06 18:55:59 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "sfe_pixel.h"
#include "hairs.h"

// void	sfe_circfill(t_img img, t_fpoint pos, float r, t_color color)
// {
// 	t_fpoint	i;
// 	float		rcalc;

// 	i.y = -r;
// 	while (i.y < r)
// 	{
// 		i.x = -r;
// 		while (i.x < r)
// 		{
// 			rcalc = sqrt(i.x * i.x + i.y * i.y);
// 			// printf("%f: %f\n", r, rcalc);
// 			if (rcalc <= r)
// 				sfe_pixel_put(img, (t_point){i.x + pos.x, i.y + pos.y}, color);
// 			i.x++;
// 		}
// 		i.y++;
// 	}
// }

void	hair_draw(t_img img, t_hair hair)
{
	(void)img;
	(void)hair;
}
