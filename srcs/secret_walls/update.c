/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 08:14:03 by marykman          #+#    #+#             */
/*   Updated: 2024/06/14 08:25:20 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "secret_walls.h"

void	secret_wall_update(t_game *game)
{
	t_dlist	*lst;

	lst = game->map.secret_walls;
	while (lst)
	{
		lst = lst->next;
	}
}
