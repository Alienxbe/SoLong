/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hitbox_colliding_spikes.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:46:43 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 18:28:23 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collisions.h"

static t_bool	is_spike_type(int block)
{
	return (block >= 0x30 && block <= 0x33);
}

static t_bool	spikes_at(t_game *game, t_fpoint pos)
{
	int	block;

	block = get_block_type(&game->map, pos);
	if (block == 0x30)
		return ((int)pos.y % SPRITE_SIZE >= SPRITE_SIZE / 2
			&& game->player.spd.y >= 0);
	else if (block == 0x33)
		return ((int)pos.y % SPRITE_SIZE <= SPRITE_SIZE / 2
			&& game->player.spd.y <= 0);
	else if (block == 0x32)
		return ((int)pos.x % SPRITE_SIZE >= SPRITE_SIZE / 2
			&& game->player.spd.x >= 0);
	else if (block == 0x31)
		return ((int)pos.x % SPRITE_SIZE <= SPRITE_SIZE / 2
			&& game->player.spd.x <= 0);
	return (false);
}

static t_bool	is_hitbox_colliding_spikes_up(t_game *game, int collisions)
{
	if (collisions & (1 << 0))
		if (spikes_at(game,
				(t_fpoint){game->player.pos.x + game->player.hitbox.p1.x,
				game->player.pos.y + game->player.hitbox.p1.y}))
			return (true);
	if (collisions & (1 << 1))
		if (spikes_at(game,
				(t_fpoint){game->player.pos.x + game->player.hitbox.p2.x,
				game->player.pos.y + game->player.hitbox.p1.y}))
			return (true);
	return (false);
}

static t_bool	is_hitbox_colliding_spikes_down(t_game *game, int collisions)
{
	if (collisions & (1 << 2))
		if (spikes_at(game,
				(t_fpoint){game->player.pos.x + game->player.hitbox.p2.x,
				game->player.pos.y + game->player.hitbox.p2.y}))
			return (true);
	if (collisions & (1 << 3))
		if (spikes_at(game,
				(t_fpoint){game->player.pos.x + game->player.hitbox.p1.x,
				game->player.pos.y + game->player.hitbox.p2.y}))
			return (true);
	return (false);
}

t_bool	is_hitbox_colliding_spikes(t_game *game)
{
	int	collisions;

	collisions = is_hitbox_colliding(&game->map, &is_spike_type,
			game->player.pos, game->player.hitbox);
	if (!collisions)
		return (false);
	if (is_hitbox_colliding_spikes_up(game, collisions)
		|| is_hitbox_colliding_spikes_down(game, collisions))
		return (true);
	return (false);
}
