/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_walls.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 07:57:45 by marykman          #+#    #+#             */
/*   Updated: 2024/08/20 21:28:06 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SECRET_WALLS_H
# define SECRET_WALLS_H

# include "so_long.h"

# define SECRET_WALLS_ASSET 0x10

void	secret_wall_init(t_game *game);
void	secret_wall_erase(t_game *game, t_img *img);
void	secret_wall_update(t_game *game);
void	secret_wall_draw(t_game *game, t_img *img);

#endif
