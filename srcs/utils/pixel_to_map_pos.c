/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_to_map_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:15:15 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 17:58:38 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	pixel_to_map_pos(t_fpoint pos)
{
	return ((t_point){
		pos.x / SPRITE_SIZE,
		pos.y / SPRITE_SIZE});
}
