/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:41:07 by marykman          #+#    #+#             */
/*   Updated: 2024/03/05 15:17:02 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collisions.h"
#include <stdio.h>

static t_point	pixel_to_map_pos(t_fpoint pos)
{
	return ((t_point){
		pos.x / SPRITE_SIZE,
		pos.y / SPRITE_SIZE});
}

int	get_block_type(const t_map *map, t_fpoint pos)
{
	t_point	p_map;

	p_map = pixel_to_map_pos(pos);
	if (pos.x < 0 || pos.x >= map->size.x * SPRITE_SIZE
		|| pos.y < 0 || pos.y >= map->size.y * SPRITE_SIZE)
		return (-1);
	return (map->tab[p_map.y][p_map.x]);
}

t_bool	is_type(const t_map *map, t_ftype f, t_fpoint pos)
{
	return (f(get_block_type(map, pos)));
}
