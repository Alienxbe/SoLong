/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:33:14 by marykman          #+#    #+#             */
/*   Updated: 2023/11/22 23:56:50 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sc_main.h"
#include "sfe_scene.h"
#include "sfe_image.h"
#include "t_sfe.h"
#include "ft_printf.h"

int	sc_main_init(t_sc_main *sc)
{
	ft_printf("Init scene main\n");
	sc->running = true;
	sfe_scene_setbg(sc->scene, 0x4000);
	sc->assets = sfe_load_sprite_sheet(sc->sfe, "assets/CelestePico8-v1-32x32.xpm", (t_point){32, 32});
	if (!sc->assets)
		return (0);

	// Test des sprites
	int i = -1;
	while (sc->assets[++i].img)
		sfe_image_cpy(sc->assets[i], *sc->scene.img, add_point((t_point){0}, (t_point){i % 16 * 32, i / 16 * 32}));
	ft_printf("Il y a %d sprites\n", i);
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