/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:37:51 by marykman          #+#    #+#             */
/*   Updated: 2023/12/29 19:14:52 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "ft_bool.h"
# include "ft_point.h"
# include "sfe_image.h"
# include "so_long.h"

# define GRAVITY			0.35
# define FALL_SPEED_MAX		7
# define JUMP_FORCE			6
# define WALL_JUMP_FORCE	6

int		player_init(t_player *player, t_point pos, t_img *assets);
void	player_update(t_game *game);
void	player_draw(t_player *player, t_img *img);

void	player_update_gravity(t_game *game);
void	player_update_jump(t_game *game);
void	player_update_wall_jump(t_game *game);

void	player_move(t_game *game);

#endif
