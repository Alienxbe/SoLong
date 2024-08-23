/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:37:51 by marykman          #+#    #+#             */
/*   Updated: 2024/08/23 15:57:47 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "collisions.h"
#include "parsing.h"

static t_bool	is_spike_type(int block)
{
	return (block >= 0x30 && block <= 0x33);
}

t_bool	check_path(t_map *map, int **tab, int x, int y)
{
	t_bool	ret;

	if (x < 0 || x >= map->size.x
		|| y < 0 || y >= map->size.y
		|| is_wall_type(tab[y][x])
		|| is_spike_type(tab[y][x]))
		return (false);
	if (x == map->exit_pos.x && y == map->exit_pos.y)
		return (true);
	tab[y][x] = 1;
	ret = false;
	ret += check_path(map, tab, x, y - 1);
	ret += check_path(map, tab, x, y + 1);
	ret += check_path(map, tab, x - 1, y);
	ret += check_path(map, tab, x + 1, y);
	return (ret);
}

t_bool	check_coin_path(t_map *map, int **tab, t_dlist *lst)
{
	t_point		pos;

	while (lst)
	{
		pos = pixel_to_map_pos(*(t_fpoint *)lst->content);
		fill_tmp_map(map, tab);
		if (!check_path(map, tab, pos.x, pos.y))
			return (false);
		lst = lst->next;
	}
	return (true);
}
