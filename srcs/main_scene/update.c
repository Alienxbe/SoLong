/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:31:23 by marykman          #+#    #+#             */
/*   Updated: 2023/12/24 14:11:20 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "t_sfe.h"
#include "sc_main.h"
#include "clouds.h"
#include "snowflakes.h"

void	draw_map(t_sc_main *sc)
{
	for (int y = 0; y < sc->game->map.size.y; y++)
		for (int x = 0; x < sc->game->map.size.x; x++)
			sfe_image_cpy(
				sc->game->assets[sc->game->map.tab[y][x]],
				*sc->scene.img,
				(t_point){
					x * sc->game->assets[0].size.x,
					y * sc->game->assets[0].size.y}
				);
}

#include "sfe_pixel.h"

int	sc_main_update(t_sc_main *sc)
{
	// sfe_scene_setbg(sc->scene, 0x0);
	sfe_pixel_fill(*sc->scene.img, (t_area){
		{sc->game->player.pos.x, sc->game->player.pos.y},
		{sc->game->player.pos.x + 32, sc->game->player.pos.y + 32}
	}, 0x0);
	player_update(sc->game);
	update_clouds(sc->game, *sc->scene.img);
	snowflakes_update(sc->game, *sc->scene.img);
	draw_clouds(sc->game, *sc->scene.img);
	draw_map(sc);
	player_draw(&sc->game->player, sc->scene.img);
	snowflakes_draw(sc->game, *sc->scene.img);
	ft_printf("FPS: %d\n", sc->sfe->fps);
	if (sc->game->player.on_ground)
		ft_printf("ON GROUND\n");
	return (sc->running);
}