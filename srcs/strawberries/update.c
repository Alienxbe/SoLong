/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:41:32 by marykman          #+#    #+#             */
/*   Updated: 2024/06/15 19:40:10 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "coins.h"
#include "strawberries.h"

static t_bool	is_collected(t_game *game, t_fpoint sb_pos)
{
	t_area		player;
	t_area		sb;

	player.p1 = ft_fpoint_to_point(game->player.pos);
	player.p2 = add_point(player.p1, game->player.hitbox.p2);
	sb.p1 = ft_fpoint_to_point(sb_pos);
	sb.p2 = add_point(sb.p1, (t_point){SPRITE_SIZE, SPRITE_SIZE});
	return (area_collision(player, sb));
}

void	strawberry_update(t_game *game)
{
	static float	i;
	t_dlist			*lst;
	t_dlist			*next;
	t_fpoint		*content;

	lst = game->map.strawberries;
	while (lst)
	{
		next = lst->next;
		content = (t_fpoint *)lst->content;
		content->y += sin(i) / 2;
		if (is_collected(game, *content))
		{
			game->player.djump = game->player.max_djump;
			//coin_remove(&game->map.strawberries, lst);
		}
		lst = next;
	}
	i += 0.1;
}
