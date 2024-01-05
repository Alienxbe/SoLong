/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:31:23 by marykman          #+#    #+#             */
/*   Updated: 2024/01/05 21:02:21 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "t_sfe.h"
#include "sfe_pixel.h"
#include "sc_main.h"
#include "clouds.h"
#include "snowflakes.h"
#include "hairs.h"
#include "player.h"

static void	map_draw(t_game *game, t_img img)
{
	t_point	pos;

	pos.y = -1;
	while (++pos.y < game->map.size.y)
	{
		pos.x = -1;
		while (++pos.x < game->map.size.x)
			sfe_image_cpy(
				game->assets[game->map.tab[pos.y][pos.x]],
				img, (t_point){
				pos.x * game->assets[0].size.x,
				pos.y * game->assets[0].size.y});
	}
}

int	sc_main_update(t_sc_main *sc)
{
	// Erase
	player_erase(sc->game, *sc->scene.img);
	snowflakes_erase(sc->game, *sc->scene.img);
	clouds_erase(sc->game, *sc->scene.img);

	// Update
	player_update(sc->game);
	clouds_update(sc->game);
	snowflakes_update(sc->game);

	// Draw
	clouds_draw(sc->game, *sc->scene.img);
	map_draw(sc->game, *sc->scene.img);
	player_draw(&sc->game->player, sc->scene.img);
	snowflakes_draw(sc->game, *sc->scene.img);
	
	ft_printf("FPS: %d\n", sc->sfe->fps);
	return (sc->running);
}