/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:18:24 by marykman          #+#    #+#             */
/*   Updated: 2024/01/18 17:35:50 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_sfe.h"
#include "sfe_color.h"
#include "sfe_image.h"
#include "sc_main.h"
#include "ft_printf.h"
#include "player.h"
#include "hairs.h"
#include "clouds.h"
#include "snowflakes.h"

static t_img	filter(t_sfe *sfe, t_img *img, size_t i)
{
	t_img	new;

	if (!sfe || !img)
		return ((t_img){0});
	(void)i;
	new = sfe_image_resize(sfe->mlx_ptr, img, (t_point)
		{img->size.x * 2, img->size.y * 2});
	sfe_color_replace(&new, 0, 0xFF000000);
	sfe_image_destroy(sfe->mlx_ptr, img);
	return (new);
}

int	sc_main_init(t_sc_main *sc)
{
	ft_printf("Init scene main\n");
	sc->running = true;
	sc->game->assets = sfe_load_sprite_sheet(sc->sfe, F_SPRITE_SHEET, (t_point)
		{16, 16}, filter);
	if (!sc->game->assets)
		return (0);
	if (!player_init(&sc->game->player, sc->game->map.player_pos,
			sc->game->assets))
		return (0);
	hairs_init(sc->game);
	clouds_init(sc->game);
	snowflakes_init(sc->game);
	return (1);
}
