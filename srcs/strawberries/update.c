/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:41:32 by marykman          #+#    #+#             */
/*   Updated: 2024/05/31 16:12:11 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "strawberries.h"

void	strawberry_update(t_game *game)
{
	static float	i;
	t_list	*lst;

	lst = game->map.coin_pos;
	while (lst)
	{
		((t_fpoint *)lst->content)->y += sin(i) / 2;
		lst = lst->next;
	}
	i += 0.1;
}
