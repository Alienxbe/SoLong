/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:14:16 by marykman          #+#    #+#             */
/*   Updated: 2024/08/21 16:41:45 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "clouds.h"

void	clouds_update(t_game *game)
{
	size_t	i;

	i = -1;
	while (++i < CLOUD_COUNT)
	{
		game->clouds[i].pos.x += game->clouds[i].speed;
		if (game->clouds[i].pos.x > game->map.pixel_size.x)
			game->clouds[i] = clouds_new_random(-300);
	}
}
