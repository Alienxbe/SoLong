/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:20:30 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 03:19:09 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sc_main.h"
#include "stats_bar.h"
#include "player.h"
#include "exit.h"
#include "strawberries.h"
#include "secret_walls.h"
#include "snowflakes.h"
#include "clouds.h"

static void	map_draw(t_game *game, t_img *img)
{
	t_point	pos;

	pos.y = -1;
	while (++pos.y < game->map.size.y)
	{
		pos.x = -1;
		while (++pos.x < game->map.size.x)
			sfe_image_cpy(
				&game->assets[game->map.tab[pos.y][pos.x]],
				img, (t_point){
				pos.x * game->assets[0].size.x,
				pos.y * game->assets[0].size.y});
	}
}

void	main_draw(t_sc_main *sc)
{
	clouds_draw(sc->game, sc->scene.img);
	map_draw(sc->game, sc->scene.img);
	strawberry_draw(sc->game, sc->scene.img);
	secret_wall_draw(sc->game, sc->scene.img);
	exit_draw(sc->game, sc->scene.img);
	player_draw(&sc->game->player, sc->scene.img);
	snowflakes_draw(sc->game, sc->scene.img);
	stats_bar_draw(sc->game, sc->scene.img, sc->sfe->fps);
}
