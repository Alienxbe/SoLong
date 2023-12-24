/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clouds.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:21:45 by marykman          #+#    #+#             */
/*   Updated: 2023/12/24 15:07:34 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOUDS_H
# define CLOUDS_H

# include "so_long.h"

# define CLOUD_COL		0x1d2b53

void	init_clouds(t_game *game);
void	update_clouds(t_game *game, t_img img);
void	draw_clouds(t_game *game, t_img img);

t_cloud	random_cloud(int x);

#endif
