/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tmp_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:17:09 by marykman          #+#    #+#             */
/*   Updated: 2024/08/21 20:17:19 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	fill_tmp_map(t_map *map, int **tmp_tab)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->size.y)
	{
		x = -1;
		while (++x < map->size.x)
			tmp_tab[y][x] = map->tab[y][x];
	}
}
