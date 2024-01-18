/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hairs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:01:24 by marykman          #+#    #+#             */
/*   Updated: 2024/01/18 17:41:54 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAIRS_H
# define HAIRS_H

# include "so_long.h"

void	hairs_init(t_game *game);
void	hairs_erase(t_game *game, t_img *img);
void	hairs_update(t_game *game);
void	hairs_draw(t_game *game, t_img *img);

#endif
