/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:20:50 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 17:56:05 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "coins.h"
#include "secret_walls.h"

static void	copy_list(t_game *game)
{
	t_dlist		*lst;
	t_fpoint	content;

	lst = game->map.secret_walls;
	while (lst)
	{
		content = *(t_fpoint *)lst->content;
		coin_add(&game->secret_walls, (t_point){content.x, content.y});
		lst = lst->next;
	}
}

void	secret_wall_init(t_game *game)
{
	ft_dlstclear(&game->secret_walls, &free);
	copy_list(game);
}
