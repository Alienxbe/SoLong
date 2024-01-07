/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clouds.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:21:45 by marykman          #+#    #+#             */
/*   Updated: 2024/01/06 18:55:13 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOUDS_H
# define CLOUDS_H

# include "so_long.h"

# define CLOUD_COL		0x1d2b53

void	clouds_init(t_game *game);
void	clouds_erase(t_game *game, t_img *img);
void	clouds_update(t_game *game);
void	clouds_draw(t_game *game, t_img *img);

t_cloud	clouds_new_random(int x);

#endif
