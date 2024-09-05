/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:18:24 by marykman          #+#    #+#             */
/*   Updated: 2024/09/05 13:04:39 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_sfe.h"
#include "sfe_color.h"
#include "sfe_image.h"
#include "sfe_pixel.h"
#include "sc_main.h"
#include "player.h"
#include "exit.h"
#include "clouds.h"
#include "snowflakes.h"
#include "strawberries.h"
#include "secret_walls.h"

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
	sc->running = true;
	sc->game->running = &sc->running;
	sc->game->assets = sfe_load_sprite_sheet(sc->sfe, F_SPRITE_SHEET,
			(t_point){16, 16}, filter);
	sc->game->alphabet = sfe_load_sprite_sheet(sc->sfe, F_ALPHABET_SHEET,
			(t_point){16, 16}, NULL);
	if (!sc->game->assets || !sc->game->alphabet)
		return (0);
	if (!player_init(&sc->game->player, sc->game->map.player_pos,
			sc->game->assets))
		return (0);
	if (!exit_init(sc->game, sc->game->map.exit_pos))
		return (0);
	clouds_init(sc->game);
	snowflakes_init(sc->game);
	strawberry_init(sc->game);
	secret_wall_init(sc->game);
	sfe_pixel_fill(sc->scene.img, (t_area){{0, 0}, sc->scene.size}, BACKGROUND_COL);
	return (1);
}
