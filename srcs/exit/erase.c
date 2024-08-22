/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 01:42:31 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 16:56:23 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "exit.h"

void	exit_erase(t_game *game, t_img *img)
{
	sfe_pixel_fill(img, (t_area){
		game->exit.pos, {
		game->exit.pos.x + SPRITE_SIZE, game->exit.pos.y + SPRITE_SIZE}},
		BACKGROUND_COL);
}
