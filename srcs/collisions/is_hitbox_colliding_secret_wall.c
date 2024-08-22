/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hitbox_colliding_secret_wall.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:52:36 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 18:28:08 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collisions.h"

static t_area	get_player_area(t_player *player, t_fpoint offset)
{
	t_area	a;
	t_point	off_pos;

	off_pos = add_point(ft_fpoint_to_point(player->pos),
			ft_fpoint_to_point(offset));
	a.p1 = add_point(off_pos, player->hitbox.p1);
	a.p2 = add_point(off_pos, player->hitbox.p2);
	return (a);
}

static t_area	get_secret_wall_area(t_fpoint *content)
{
	t_area	a;

	a.p1 = ft_fpoint_to_point(*content);
	a.p2 = add_point(a.p1, (t_point){SPRITE_SIZE * 2 - 1, SPRITE_SIZE * 2 - 1});
	return (a);
}

t_dlist	*is_hitbox_colliding_secret_wall(t_player *player, t_fpoint offset,
	t_dlist *secret_walls)
{
	t_area	player_area;

	player_area = get_player_area(player, offset);
	while (secret_walls)
	{
		if (area_collision(
				player_area,
				get_secret_wall_area(secret_walls->content)))
			return (secret_walls);
		secret_walls = secret_walls->next;
	}
	return (0);
}
