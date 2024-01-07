/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:04:27 by marykman          #+#    #+#             */
/*   Updated: 2024/01/07 14:09:00 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "utils.h"
#include "player.h"
#include <stdio.h>

static void	player_move_x(t_game *game, float x)
{
	int		step;
	float	i;

	step = ft_signfloat(x);
	i = 0;
	while (i < ft_abs(x))
	{
		if (!player_is_solid(game, (t_fpoint){step, 0})
			&& !player_is_oob(game, (t_fpoint){step, 0}))
			game->player.pos.x += step;
		else
		{
			game->player.spd.x = 0;
			break ;
		}
		i++;
	}
}

static void	player_move_y(t_game *game, float y)
{
	int		step;
	float	i;

	step = ft_signfloat(y);
	i = 0;
	while (i < ft_abs(y))
	{
		if (!player_is_solid(game, (t_fpoint){0, step})
			&& !player_is_oob(game, (t_fpoint){0, step}))
			game->player.pos.y += step;
		else
		{
			game->player.spd.y = 0;
			break ;
		}
		i++;
	}
}

void	player_move(t_game *game)
{
	player_move_x(game, game->player.spd.x);
	player_move_y(game, game->player.spd.y);
}
