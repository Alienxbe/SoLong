/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:54:08 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 18:30:47 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_string.h"
#include "parsing.h"

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
	map->player_pos = (t_point){-1, -1};
	map->exit_pos = (t_point){-1, -1};
	ret = parse_map(map, fd);
	if (close(fd) < 0)
		ret = MAP_CLOSE_ERROR;
	map->pixel_size = (t_point){map->size.x * SPRITE_SIZE,
		map->size.y * SPRITE_SIZE};
	if (!ret)
		ret = check_map(map);
	return (ret);
}
