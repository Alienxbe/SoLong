/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 01:15:52 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 17:01:01 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_error	set_exit(t_map *map, t_point pos)
{
	static int	exit_count;

	if (exit_count)
		return (PARSING_MULTIPLE_EXIT);
	map->exit_pos = pos;
	exit_count++;
	return (SUCCESS);
}
