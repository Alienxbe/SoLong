/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:31:23 by marykman          #+#    #+#             */
/*   Updated: 2023/12/20 21:22:56 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "t_sfe.h"
#include "sc_main.h"

void	draw_map(t_sc_main *sc)
{
	// sfe_scene_setbg(sc->scene, 0x0);
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

int	sc_main_update(t_sc_main *sc)
{
	if (sc->game->active_keys[GAME_KEY_LEFT])
	{
		sc->game->player.pos.x -= 4;
		sc->game->player.direction = 1;
	}
	if (sc->game->active_keys[GAME_KEY_RIGHT])
	{
		sc->game->player.pos.x += 4;
		sc->game->player.direction = 0;
	}

	draw_map(sc);
	player_draw(&sc->game->player, sc->scene.img);
	ft_printf("FPS: %d\n", sc->sfe->fps);
	return (sc->running);
}