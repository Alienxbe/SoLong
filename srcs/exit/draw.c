/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 01:31:36 by marykman          #+#    #+#             */
/*   Updated: 2024/08/21 01:49:31 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_image.h"
#include "exit.h"

void	exit_draw(t_game *game, t_img *img)
{
	sfe_image_cpy(
			game->assets + EXIT_ASSET + game->exit.frame,
			img,
			game->exit.pos);
}
