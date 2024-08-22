/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:06:35 by marykman          #+#    #+#             */
/*   Updated: 2024/08/21 20:38:13 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "ft_memory.h"
#include "collisions.h"
#include "parsing.h"

static int	**free_ret(int **tab, int max)
{
	int	i;

	i = -1;
	while (++i < max)
		free(tab[i]);
	free(tab);
	return (NULL);
}

static int	**create_tmp_map(t_map *map)
{
	int	**tab;
	int	i;

	tab = ft_calloc(map->size.y, sizeof(*tab));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < map->size.y)
	{
		tab[i] = ft_calloc(map->size.x, sizeof(**tab));
		if (!tab[i])
			return (free_ret(tab, i));
	}
	return (tab);
}

static t_error	check_closed_map(t_map *map)
{
	int	i;

	// Horizontal
	i = -1;
	while (++i < map->size.x)
		if (!is_wall_type(map->tab[0][i])
			|| !is_wall_type(map->tab[map->size.y - 1][i]))
			return (UNCLOSED_MAP);
	// Vertical
	i = -1;
	while (++i < map->size.y)
		if (!is_wall_type(map->tab[i][0])
			|| !is_wall_type(map->tab[i][map->size.x - 1]))
			return (UNCLOSED_MAP);
	return (SUCCESS);
}

t_error	check_map(t_map *map)
{
	t_error	ret;
	int		**tmp_tab;

	ret = SUCCESS;
	if (map->player_pos.x == -1)
		return (MISSING_PLAYER);
	if (map->exit_pos.x == -1)
		return (MISSING_EXIT);
	if (!map->strawberries && !map->secret_walls)
		return (MISSING_COIN);
	if (check_closed_map(map) && PARSING_MODE == 1)
		return (UNCLOSED_MAP);
	tmp_tab = create_tmp_map(map);
	if (!tmp_tab)
		return (MALLOC_ERROR);
	fill_tmp_map(map, tmp_tab);
	if (!check_path(map, tmp_tab, map->player_pos.x, map->player_pos.y)
		|| !check_coin_path(map, tmp_tab, map->strawberries)
		|| !check_coin_path(map, tmp_tab, map->secret_walls))
		ret = NO_VALID_PATH;
	free_ret(tmp_tab, map->size.y);
	return (ret);
}
