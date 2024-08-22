/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:29:34 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 14:57:55 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "ft_memory.h"
#include "ft_math.h"
#include "ft_string.h"
#include "ft_ctype.h"
#include "coins.h"
#include "parsing.h"

static t_error	parse_special_char(t_map *map, char *line, int i)
{
	if (*++line == 'P')
	{
		if (set_player(map, (t_point){i, map->size.y}))
			return (PARSING_MULTIPLE_PLAYER);
	}
	else if (*line == 'C')
	{
		if (coin_add(&map->strawberries, (t_point){i * SPRITE_SIZE, map->size.y * SPRITE_SIZE}))
			return (MALLOC_ERROR);
	}
	else if (*line == 'W')
	{
		if (coin_add(&map->secret_walls, (t_point){i * SPRITE_SIZE, map->size.y * SPRITE_SIZE}))
			return (MALLOC_ERROR);
	}
	else if (*line == 'E')
	{
		if (set_exit(map, (t_point){i, map->size.y}))
			return (PARSING_MULTIPLE_EXIT);
	}
	else
		return (PARSING_WRONG_CHAR);
	return (SUCCESS);
}

static t_error	parse_mandatory_char(t_map *map, int *tab, char *line, int i)
{
	if (*line == '0' || *line == '1')
		tab[i] = ft_todigit(*line);
	else if (*line == 'C')
	{
		if (coin_add(&map->strawberries, (t_point){i * SPRITE_SIZE, map->size.y * SPRITE_SIZE}))
			return (MALLOC_ERROR);
	}
	else if (*line == 'E')
	{
		if (set_exit(map, (t_point){i, map->size.y}))
			return (PARSING_MULTIPLE_EXIT);
	}
	else if (*line == 'P')
	{
		if (set_player(map, (t_point){i, map->size.y}))
			return (PARSING_MULTIPLE_PLAYER);
	}
	else
		return (PARSING_WRONG_CHAR);
	return (SUCCESS);
}

static t_error	parse_bonus_char(t_map *map, int *tab, char *line, int i)
{
	t_error	ret;
	char	*endptr;
	
	if (*line == 'x')
	{
		ret = parse_special_char(map, line, i);
		if (ret)
			return (ret);
	}
	else
	{
		tab[i] = ft_strtol_l(line, &endptr, BASE_HEXA_L, 2);
		if (endptr != line + 2)
			return (PARSING_WRONG_CHAR);
	}
	return (SUCCESS);
}

t_error	parse_content(t_map *map, int **tab, char *line)
{
	t_error	ret;
	size_t	i;

	*tab = ft_calloc(sizeof(**tab), ft_strlen(line) / PARSING_MODE);
	if (!*tab)
		return (MALLOC_ERROR);
	ret = SUCCESS;
	i = 0;
	while (*line && !ret)
	{
		if (PARSING_MODE == 1)
			ret = parse_mandatory_char(map, *tab, line, i);
		else 
			ret = parse_bonus_char(map, *tab, line, i);
		i++;
		line += PARSING_MODE;
	}
	if (ret)
		free(*tab);
	return (ret);
}
