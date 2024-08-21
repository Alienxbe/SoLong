/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:12:04 by marykman          #+#    #+#             */
/*   Updated: 2024/08/21 01:18:09 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_error	set_player(t_map *map, t_point pos)
{
	static int	player_count;

	if (player_count)
		return (PARSING_MULTIPLE_PLAYER);
	map->player_pos = pos;
	player_count++;
	return (SUCCESS);
}
