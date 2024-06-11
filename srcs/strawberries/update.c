/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:41:32 by marykman          #+#    #+#             */
/*   Updated: 2024/06/11 16:23:15 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "ft_printf.h"
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
	t_dlist		*lst;
	t_dlist		*tmp;
	t_fpoint	*content;

	lst = game->map.coin_pos;
	while (lst)
	{
		tmp = lst->next;
		content = (t_fpoint *)lst->content;
		content->y += sin(i) / 2; //update position
		if (is_collected(game, *content))
		{
			ft_printf("REMOVED : %p\n", lst);
			if (!lst->previous)
				game->map.coin_pos = lst->next;
			ft_dlstdelone(ft_dlstremove(lst), &free);
		}
		lst = tmp;
	}
	// ft_printf("END OF LOOP\n");
	i += 0.1;
}
