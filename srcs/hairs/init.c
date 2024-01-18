/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:09:09 by marykman          #+#    #+#             */
/*   Updated: 2024/01/18 17:39:13 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hairs.h"

void	hairs_init(t_game *game)
{
	size_t	i;

	i = -1;
	while (++i < HAIR_COUNT)
	{
		game->hairs[i].texture = game->assets + (0xe0 + i);
		game->hairs[i].pos = (t_fpoint){game->player.pos.x + 20 * i, game->player.pos.y};
	}
}
