/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:06:32 by marykman          #+#    #+#             */
/*   Updated: 2024/08/21 20:22:32 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "so_long.h"
# include "errors.h"

# ifdef BONUS
#  define PARSING_MODE 2
# else
#  define PARSING_MODE 1
#endif

t_error	set_player(t_map *map, t_point pos);
t_error	set_exit(t_map *map, t_point pos);

t_error	parsing(t_map *map, const char *filename);
t_error	parse_map(t_map *map, int fd);
t_error	parse_content(t_map *map, int **tab, char *line);

t_error	check_map(t_map *map);
t_bool	check_path(t_map *map, int **tab, int x, int y);
t_bool	check_coin_path(t_map *map, int **tab, t_dlist *lst);

void	fill_tmp_map(t_map *map, int **tmp_tab);

#endif
