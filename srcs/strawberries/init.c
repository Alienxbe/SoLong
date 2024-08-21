/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:49:41 by marykman          #+#    #+#             */
/*   Updated: 2024/08/21 18:08:38 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "coins.h"
#include "strawberries.h"

static void	copy_list(t_game *game)
{
	t_dlist *lst;
	t_fpoint	content;

	lst = game->map.strawberries;
	while (lst)
	{
		content = *(t_fpoint *)lst->content;
		coin_add(&game->strawberries, (t_point){content.x, content.y - 5});
		lst = lst->next;
	}
}

void	strawberry_init(t_game *game)
{
	ft_dlstclear(&game->strawberries, &free);
	copy_list(game);
}
