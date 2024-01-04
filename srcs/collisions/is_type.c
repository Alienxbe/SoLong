/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:41:07 by marykman          #+#    #+#             */
/*   Updated: 2024/01/03 20:47:29 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collisions.h"
#include <stdio.h>

t_bool	is_type(const t_map *map, t_ftype f, t_fpoint pos)
{
	t_point	p_map;

	p_map.x = pos.x / SPRITE_SIZE;
	p_map.y = pos.y / SPRITE_SIZE;
	if (pos.x < 0 || pos.x >= map->size.x * SPRITE_SIZE
		|| pos.y < 0 || pos.y >= map->size.y * SPRITE_SIZE)
		return (f(-1));
	return (f(map->tab[p_map.y][p_map.x]));
}
