/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:33:14 by marykman          #+#    #+#             */
/*   Updated: 2023/12/12 14:54:56 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sc_main.h"
#include "sfe_scene.h"
#include "sfe_image.h"
#include "t_sfe.h"
#include "ft_printf.h"
#include "sfe_color.h"
#include "sfe_pixel.h"

static t_img	filter(t_sfe *sfe, t_img img)
{
	t_img	new;

	new = sfe_image_resize(sfe->mlx_ptr, img, (t_point){img.size.x * 2, img.size.y * 2});
	sfe_color_replace(new, 0, 0xFF000000);
	sfe_image_destroy(sfe->mlx_ptr, img);
	return (new);
}

int	sc_main_init(t_sc_main *sc)
{
	ft_printf("Init scene main\n");
	sc->running = true;
	sfe_scene_setbg(sc->scene, 0x0);
	sc->assets = sfe_load_sprite_sheet(sc->sfe, "assets/CelestePico8.xpm", (t_point){16, 16}, filter);
	if (!sc->assets)
		return (0);

	for (int y = 0; y < sc->map.size.y; y++)
		for (int x = 0; x < sc->map.size.x; x++)
			sfe_image_cpy(sc->assets[sc->map.tab[y][x]], *sc->scene.img, (t_point){x * sc->assets[0].size.x, y * sc->assets[0].size.y});
	return (1);
}

int		sc_main_destroy(t_sc_main *sc)
{
	int	i;

	i = -1;
	while (sc->assets[++i].img)
		sfe_image_destroy(sc->sfe->mlx_ptr, sc->assets[i]);
	sc->assets = NULL;
	return (0);
}

int	sc_main_update(t_sc_main *sc)
{
	return (sc->running);
}