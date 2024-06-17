/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 08:14:03 by marykman          #+#    #+#             */
/*   Updated: 2024/06/14 21:24:26 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "utils.h"
#include "collisions.h"
#include "coins.h"
#include "secret_walls.h"
#include "ft_printf.h"

static t_dlist	*is_player_breaking_wall(t_game *game)
{
	if (game->player.dash_time > 1)
		return (is_hitbox_colliding_secret_wall(&game->player, game->player.dash_target, game->map.secret_walls));
	return (NULL);
}

void	secret_wall_update(t_game *game)
{
	t_dlist	*broken_wall;
	t_fpoint	*content;

	broken_wall = is_player_breaking_wall(game);
	if (!broken_wall)
		return ;
	content = (t_fpoint *)broken_wall->content;
	coin_add(&game->map.strawberries, (t_point){content->x + 16, content->y + 16});
	coin_remove(&game->map.secret_walls, broken_wall);
	game->player.dash_time = 0;
	game->player.spd = (t_fpoint){-ft_signfloat(game->player.spd.x) * 7, -5};
}
