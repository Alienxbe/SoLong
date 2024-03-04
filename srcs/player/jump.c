/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:07:57 by marykman          #+#    #+#             */
/*   Updated: 2024/03/04 16:59:55 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_update_jump(t_game *game)
{
	if (game->player.jbuffer && game->player.grace)
	{
		game->player.spd.y = -JUMP_FORCE;
		game->player.jbuffer = 0;
		game->player.grace = 0;
	}
}
