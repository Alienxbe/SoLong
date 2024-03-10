/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hitbox_colliding_spikes.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:46:43 by marykman          #+#    #+#             */
/*   Updated: 2024/03/10 18:00:17 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collisions.h"
#include "ft_printf.h"

static t_bool	is_spike_type(int block)
{
	return (block >= 0x30 && block <= 0x33);
}

static void	foo(t_game *game, t_fpoint pos)
{
	int block;
	
	block = get_block_type(&game->map, pos);
	if (block == 0x30)
		;
	else if (block == 0x31)
		;
	else if (block == 0x31)
		;
	else if (block == 0x31)
		;
}

t_bool	is_hitbox_colliding_spikes(t_game *game)
{
	int collisions;
	
	collisions = is_hitbox_colliding(&game->map, &is_spike_type, game->player.pos,
		game->player.hitbox);
	if (!collisions)
		return (false);
	if (collisions & (1 << 0)) // UL
		foo(game, (t_fpoint){game->player.pos.x + game->player.hitbox.p1.x, game->player.pos.x + game->player.hitbox.p1.x});
	if (collisions & (1 << 1)) // UR
		foo(game, (t_fpoint){game->player.pos.x + game->player.hitbox.p1.x, game->player.pos.x + game->player.hitbox.p2.x});
	if (collisions & (1 << 2)) // DR
		foo(game, (t_fpoint){game->player.pos.x + game->player.hitbox.p2.x, game->player.pos.x + game->player.hitbox.p2.x});
	if (collisions & (1 << 3)) // DL
		foo(game, (t_fpoint){game->player.pos.x + game->player.hitbox.p2.x, game->player.pos.x + game->player.hitbox.p1.x});
	return (true);
}