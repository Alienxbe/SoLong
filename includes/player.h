/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:37:51 by marykman          #+#    #+#             */
/*   Updated: 2023/12/20 19:51:37 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "ft_bool.h"
# include "ft_point.h"
# include "sfe_image.h"

typedef struct s_player
{
	t_point	pos;
	int		frame;
	int		direction;
	t_img	*assets;
}	t_player;

int		player_init(t_player *player, t_point pos, t_img *assets);
void	player_draw(t_player *player, t_img *img);

#endif
