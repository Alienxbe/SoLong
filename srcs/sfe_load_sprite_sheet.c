/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfe_load_sprite_sheet.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:37:37 by marykman          #+#    #+#             */
/*   Updated: 2023/11/24 17:07:40 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_memory.h"
#include "ft_printf.h"
#include "t_sfe.h"
#include "sfe.h"
#include "sfe_image.h"
#include "sc_main.h"

/*
** The end of sprites is defined by an t_img that has a NULL `img`
*/
t_img	*sfe_load_sprite_sheet(t_sfe *sfe, char *filename, t_point sprite_size,
			t_filter filter)
{
	t_img	sheet;
	t_img	*sprites;
	t_point	sprite_dim;
	int		sprite_count;
	int		i;

	sheet = sfe_xpm_file_to_image(sfe->mlx_ptr, filename);
	if (!sheet.img)
		return (NULL);
	sprite_dim.x = sheet.size.x / sprite_size.x;
	sprite_dim.y = sheet.size.y / sprite_size.y;
	sprite_count = sprite_dim.x * sprite_dim.y;
	sprites = ft_calloc(sprite_count + 1, sizeof(t_img));
	if (sprites)
	{
		i = -1;
		while (++i < sprite_count)
		{
			t_point	pos;
			t_area	a;

			pos = new_point(i % sprite_dim.x, i / sprite_dim.y);
			a.p1 = new_point(pos.x * sprite_size.x, pos.y * sprite_size.y);
			a.p2 = add_point(a.p1, sprite_size);
			sprites[i] = sfe_image_sub(sfe->mlx_ptr, sheet, a);
			if (filter)
				sprites[i] = filter(sfe, sprites[i]);
			if (!sprites[i].img) // Must handle error and free
				return (NULL);
		}
	}
	sfe_image_destroy(sfe->mlx_ptr, sheet);
	return (sprites);
}