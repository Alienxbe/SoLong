/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:37:51 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 17:25:39 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "ft_bool.h"
# include "ft_point.h"
# include "sfe_image.h"
# include "so_long.h"

# define PLAYER_GRAVITY_ACCEL		0.42
# define PLAYER_GRAVITY_MAX			5.6

# define PLAYER_WALLSLIDE_MAX		1.5

# define PLAYER_MOVE_GROUND_ACCEL	2.4
# define PLAYER_MOVE_AIR_ACCEL		0.6
# define PLAYER_MOVE_MAX			4

# define PLAYER_DASH_ACCEL			0.75

# define PLAYER_MOVE_DECEL			0.6

# define JUMP_FORCE					7.5
# define WALL_JUMP_FORCE			7.1
# define PLAYER_JUMP_BUFFER			6
# define PLAYER_GRACE				6
# define PLAYER_MAX_DJUMP			1
# define D_FULL						11.5
# define D_HALF						9.775

int		player_init(t_player *player, t_point pos, t_img *assets);
void	player_erase(t_game *game, t_img *img);
void	player_update(t_game *game);
void	player_draw(t_player *player, t_img *img);
void	player_update_state_jump(t_game *game);
void	player_update_state_jbuffer(t_game *game);
void	player_update_state_grace(t_game *game);
void	player_update_state_dash(t_game *game);
void	player_update_gravity(t_game *game);
void	player_update_speed(t_game *game);
void	player_update_jump(t_game *game);
void	player_update_dash(t_game *game);
void	player_update_dash_speed(t_game *game);
void	player_update_wall_jump(t_game *game);
void	player_update_animation(t_game *game);
void	player_move(t_game *game);

t_bool	player_isdead(t_game *game);
void	player_death(t_game *game);

t_bool	player_is_solid(t_game *game, t_fpoint pos);
t_bool	player_is_oob(t_game *game, t_fpoint pos);

#endif
