/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:29:34 by marykman          #+#    #+#             */
/*   Updated: 2024/05/31 16:17:20 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "ft_memory.h"
#include "ft_math.h"
#include "ft_string.h"
#include "parsing.h"

static t_error	parse_special_char(t_map *map, char *line, int i)
{
	ft_printf("PLAYER PLAYER %d %d\n", i, map->size.y);
	if (*++line == 'P')
	{
		if (add_player(map, (t_point){i, map->size.y}))
			return (PARSING_MULTIPLE_PLAYER);
	}
	else if (*line == 'C')
	{
		if (add_coin(map, (t_point){i, map->size.y}))
			return (PARSING_COIN_ERROR);
	}
	else if (*line == 'E')
		;
	else
		return (PARSING_WRONG_CHAR);
	ft_printf("SUCCES\n");
	return (SUCCESS);
}

t_error	parse_content(t_map *map, int **tab, char *line)
{
	t_error	ret;
	size_t	i;
	char	*endptr;

	*tab = ft_calloc(sizeof(**tab), ft_strlen(line) / 2);
	if (!*tab)
		return (MALLOC_ERROR);
	ret = SUCCESS;
	i = 0;
	while (*line && !ret)
	{
		if (*line == 'x')
		{
			if (parse_special_char(map, line, i++))
				ret = PARSING_WRONG_CHAR;
		}
		else
		{
			(*tab)[i++] = ft_strtol_l(line, &endptr, BASE_HEXA_L, 2);
			if (endptr != line + 2)
				ret = PARSING_WRONG_CHAR;
		}
		line += 2;
	}
	if (ret)
		free(*tab);
	return (ret);
}
