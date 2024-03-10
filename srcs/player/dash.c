/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:00:10 by marykman          #+#    #+#             */
/*   Updated: 2024/03/05 11:56:38 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_math.h"
#include "sfe_pixel.h"
#include "sfe_color.h"
#include "player.h"
#include "utils.h"

#define D_FULL	10
#define D_HALF	(D_FULL * 0.9)

void	player_update_dash(t_game *game)
{
	if (game->player.djump <= 0 || !game->player.dash)
		return ;
	game->player.djump--;
	game->player.dash_time = 5;
	
	if (game->player.input.x)
	{
		if (game->player.input.y) // Diagonals
		{
			game->player.spd.x = game->player.input.x * D_HALF;
			game->player.spd.y = game->player.input.y * D_HALF;
		}
		else //Horizontal
		{
			game->player.spd.x = game->player.input.x * D_FULL;
			game->player.spd.y = 0;
		}
	}
	else
	{
		if (game->player.input.y) // Vertical
		{
			game->player.spd.x = 0;
			game->player.spd.y = game->player.input.y * D_FULL;
		}
	}
	game->player.dash_target.x = 3 * ft_signfloat(game->player.spd.x);
	game->player.dash_target.y = 3 * ft_signfloat(game->player.spd.y);
}

void	player_update_dash_speed(t_game *game)
{
	game->player.dash_time--;
	game->player.spd.x = ft_appr(game->player.spd.x, game->player.dash_target.x, PLAYER_DASH_ACCEL);
	game->player.spd.y = ft_appr(game->player.spd.y, game->player.dash_target.y, PLAYER_DASH_ACCEL);
}
