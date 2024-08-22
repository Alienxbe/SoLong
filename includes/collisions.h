/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:33:37 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 16:33:30 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISIONS_H
# define COLLISIONS_H

# include "so_long.h"

typedef t_bool	(*t_ftype)(int);

int		get_block_type(const t_map *map, t_fpoint pos);
t_bool	is_type(const t_map *map, t_ftype f, t_fpoint pos);
t_bool	is_wall(const t_map *map, t_fpoint pos);
t_bool	is_wall_type(int block);
int		is_hitbox_colliding(const t_map *map, t_ftype f, t_fpoint pos,
			t_area hitbox);

t_bool	is_hitbox_colliding_spikes(t_game *game);
t_dlist	*is_hitbox_colliding_secret_wall(t_player *player, t_fpoint offset,
			t_dlist *secret_walls);

#endif
