/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_coin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:29:26 by marykman          #+#    #+#             */
/*   Updated: 2024/05/31 13:12:23 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parsing.h"

t_error	add_coin(t_map *map, t_point pos)
{
	t_point	*content;

	content = malloc(sizeof(*content));
	if (!content)
		return (MALLOC_ERROR);
	*content = pos;
	if (!ft_lstadd_back(&map->coin_pos, ft_lstnew(content)))
	{
		free(content);
		return (MALLOC_ERROR);
	}
	return (SUCCESS);
}
