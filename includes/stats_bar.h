/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_bar.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 02:20:05 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 03:36:28 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATS_BAR_H
# define STATS_BAR_H

# include "so_long.h"

# define STATS_BAR_SIZE			20
# define STATS_BAR_BACKGROUND	0x808080

void	stats_bar_draw(t_game *game, t_img *img, unsigned int fps);

#endif
