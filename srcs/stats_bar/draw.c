/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 02:18:55 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 18:17:37 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "sfe_pixel.h"
#include "sfe_image.h"
#include "utils.h"
#include "stats_bar.h"

static void	draw_background(t_game *game, t_img *img)
{
	t_area	a;

	a.p1 = (t_point){0, game->map.pixel_size.y};
	a.p2 = (t_point){game->map.pixel_size.x,
		game->map.pixel_size.y + STATS_BAR_SIZE};
	sfe_pixel_fill(img, a, STATS_BAR_BACKGROUND);
}

static void	draw_fps_counter(t_game *game, t_img *img, unsigned int fps)
{
	t_point	pos;
	char	*fps_string;

	pos = (t_point){game->map.pixel_size.x - 2 - 3 * 16,
		game->map.pixel_size.y + 2};
	draw_string(game, img, pos, "FPS");
	fps_string = ft_itoa(fps);
	pos.x -= 16 * ft_strlen(fps_string);
	draw_string(game, img, pos, fps_string);
	if (fps_string)
		free(fps_string);
}

static void	draw_step_counter(t_game *game, t_img *img)
{
	t_point	pos;
	char	*steps_string;

	pos = (t_point){2, game->map.pixel_size.y + 2};
	draw_string(game, img, pos, "STEPS:");
	pos.x += 16 * ft_strlen("STEPS:");
	steps_string = ft_itoa(game->player.steps);
	draw_string(game, img, pos, steps_string);
	if (steps_string)
		free(steps_string);
}

static void	draw_coin_counter(t_game *game, t_img *img)
{
	t_point	pos;

	pos = (t_point){game->map.pixel_size.x / 2 - 8, game->map.pixel_size.y + 2};
	draw_string(game, img, pos, ":");
}

void	stats_bar_draw(t_game *game, t_img *img, unsigned int fps)
{
	draw_background(game, img);
	draw_fps_counter(game, img, fps);
	draw_step_counter(game, img);
	draw_coin_counter(game, img);
}
