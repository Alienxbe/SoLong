/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hitbox_colliding_spikes.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:46:43 by marykman          #+#    #+#             */
/*   Updated: 2024/04/02 23:49:53 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collisions.h"
#include "ft_printf.h"

static t_bool	is_spike_type(int block)
{
	return (block >= 0x30 && block <= 0x33);
}

static t_bool	spikes_at(t_game *game, t_fpoint pos)
{
	int block;

	block = get_block_type(&game->map, pos);
	if (block == 0x30)
		return ((int)pos.y % SPRITE_SIZE >= SPRITE_SIZE / 2 && game->player.spd.y >= 0);
	else if (block == 0x33)
		return ((int)pos.y % SPRITE_SIZE <= SPRITE_SIZE / 2 && game->player.spd.y <= 0);
	else if (block == 0x32) // left
		return ((int)pos.x % SPRITE_SIZE >= SPRITE_SIZE / 2 && game->player.spd.x >= 0);
	else if (block == 0x31) // right
		return ((int)pos.x % SPRITE_SIZE <= SPRITE_SIZE / 2 && game->player.spd.x <= 0);
	return (false);
}

t_bool	is_hitbox_colliding_spikes(t_game *game)
{
	int collisions;
	
	collisions = is_hitbox_colliding(&game->map, &is_spike_type, game->player.pos,
		game->player.hitbox);
	if (!collisions)
		return (false);
	if (collisions & (1 << 0)) // UL
		if (spikes_at(game, (t_fpoint){game->player.pos.x + game->player.hitbox.p1.x, game->player.pos.y + game->player.hitbox.p1.y}))
			return (true);
	if (collisions & (1 << 1)) // UR
		if (spikes_at(game, (t_fpoint){game->player.pos.x + game->player.hitbox.p2.x, game->player.pos.y + game->player.hitbox.p1.y}))
			return (true);
	if (collisions & (1 << 2)) // DR
		if (spikes_at(game, (t_fpoint){game->player.pos.x + game->player.hitbox.p2.x, game->player.pos.y + game->player.hitbox.p2.y}))
			return (true);
	if (collisions & (1 << 3)) // DL
		if (spikes_at(game, (t_fpoint){game->player.pos.x + game->player.hitbox.p1.x, game->player.pos.y + game->player.hitbox.p2.y}))
			return (true);
	return (false);
}