/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:06:32 by marykman          #+#    #+#             */
/*   Updated: 2024/08/21 01:17:53 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "so_long.h"
# include "errors.h"

t_error	set_player(t_map *map, t_point pos);
t_error	set_exit(t_map *map, t_point pos);

t_error	parsing(t_map *map, const char *filename);
t_error	parse_map(t_map *map, int fd);
t_error	parse_content(t_map *map, int **tab, char *line);

#endif
