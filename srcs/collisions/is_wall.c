/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:51:30 by marykman          #+#    #+#             */
/*   Updated: 2024/01/03 19:02:06 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collisions.h"

static t_bool	is_wall_type(int block)
{
	return (block >= 1 && block <= 0x25);
}

t_bool	is_wall(const t_map *map, t_fpoint pos)
{
	return (is_type(map, &is_wall_type, pos));
}
