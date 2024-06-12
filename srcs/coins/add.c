/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:29:26 by marykman          #+#    #+#             */
/*   Updated: 2024/06/12 19:39:00 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include "coins.h"

t_error	coin_add(t_dlist **list, t_point pos)
{
	t_fpoint	*content;

	content = malloc(sizeof(*content));
	if (!content)
		return (MALLOC_ERROR);
	*content = (t_fpoint){pos.x * SPRITE_SIZE, pos.y * SPRITE_SIZE};
	if (!ft_dlstadd_back(list, ft_dlstnew(content)))
	{
		free(content);
		return (MALLOC_ERROR);
	}
	return (SUCCESS);
}
