/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 01:22:32 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 16:56:35 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int	exit_init(t_game *game, t_point pos)
{
	if (pos.x == -1 && pos.y == -1)
		return (0);
	game->exit.pos = (t_point){
		pos.x * SPRITE_SIZE,
		pos.y * SPRITE_SIZE};
	game->exit.hitbox.p2 = (t_point){SPRITE_SIZE, SPRITE_SIZE};
	return (1);
}
