/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:50:49 by marykman          #+#    #+#             */
/*   Updated: 2024/01/07 14:08:44 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "player.h"

void	player_erase(t_game *game, t_img *img)
{
	sfe_pixel_fill(img, (t_area){{
		game->player.pos.x, game->player.pos.y}, {
		game->player.pos.x + SPRITE_SIZE, game->player.pos.y + SPRITE_SIZE}},
		BACKGROUND_COL);
}
