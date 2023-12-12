/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:54:08 by marykman          #+#    #+#             */
/*   Updated: 2023/12/12 16:21:53 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_string.h"
#include "get_next_line.h"
#include "ft_ctype.h"
#include "ft_list.h"
#include "ft_math.h"
#include "so_long.h"
#include "ft_printf.h"

static t_error	add_player(t_map *map, t_point pos)
{
	static int	player_count;

	if (player_count)
		return (PARSING_MULTIPLE_PLAYER);
	map->player_pos = (t_point){pos.x * 32, pos.y * 32};
	player_count++;
	return (SUCCESS);
}

static t_error	parse_special_char(t_map *map, char *line, int i)
{
	ft_printf("PLAYER PLAYER %d %d\n", i, map->size.y);
	if (*++line == 'P')
	{
		if (add_player(map, (t_point){i, map->size.y}))
			return (PARSING_MULTIPLE_PLAYER);
	}
	else if (*line == 'C')
		;
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

	*tab = malloc(sizeof(**tab) * (ft_strlen(line) / 2));
	if (!*tab)
		return (MALLOC_ERROR);
	ret = SUCCESS;
	i = 0;
	while (*line && !ret)
	{
		if (*line == 'x')
		{
			if (parse_special_char(map, line, i))
				ret = PARSING_WRONG_CHAR;
			(*tab)[i++] = 0;
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

t_error	parse_line(t_map *map, t_list **lines, char *line)
{
	t_error	ret;
	t_list	*lst;
	int		*content;

	if (!line)
		return (MALLOC_ERROR);
	if (!map->size.y)
		map->size.x = ft_strlen(line) / 2;
	if (map->size.x != (int)ft_strlen(line) / 2 || map->size.x % 2 || !*line)
		return (PARSING_WRONG_LINE_LEN);
	ret = parse_content(map, &content, line);
	if (ret)
		return (ret);
	lst = ft_lstnew(content);
	if (!lst)
		return (MALLOC_ERROR);
	ft_lstadd_back(lines, lst);
	map->size.y++;
	return (SUCCESS);
}

t_error	join_list(t_map *map, t_list *lines, t_error ret)
{
	int	i;

	if (ret)
		return (ret);
	map->tab = malloc(sizeof(*map->tab) * map->size.y);
	if (!map->tab)
		return (MALLOC_ERROR);
	i = 0;
	while (lines)
	{
		map->tab[i] = lines->content;
		lines = lines->next;
		i++;
	}
	return (SUCCESS);
}

t_error	parse_map(t_map *map, int fd)
{
	t_error	ret;
	t_list	*lines;
	char	*line;
	int		gnl;

	lines = NULL;
	gnl = 1;
	ret = SUCCESS;
	while (gnl > 0 && !ret)
	{
		gnl = get_next_line(fd, &line);
		ret = parse_line(map, &lines, line);
		free(line);
	}
	ret = join_list(map, lines, ret);
	if (ret)
		ft_lstclear(&lines, &free);
	else
		ft_lstclear(&lines, NULL);
	return (ret);
}

/**
 * @brief This function take a file as parameter. Reads and then parses it
 * into a two dimensional integers array (`t_map`).
 * If an error occured, a NULL pointer is returned instead
 * 
 * @param filename Name of the file containing the map
 * @return two dimensional array containing the map
 */
t_error	parsing(t_map *map, const char *filename)
{
	t_error	ret;
	int		fd;

	if (!ft_strendwith(filename, MAPFILE_SUFFIX))
		return (MAP_WRONG_EXTENSION);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (MAP_FILE_NOT_FOUND);
	ret = parse_map(map, fd);
	if (close(fd) < 0)
		return (MAP_CLOSE_ERROR); // Need to free the map
	ft_printf("%d\n", ret);
	return (ret);
}
