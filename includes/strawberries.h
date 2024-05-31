/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strawberries.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:59:36 by marykman          #+#    #+#             */
/*   Updated: 2024/05/31 14:45:09 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRAWBERRIES_H
# define STRAWBERRIES_H

# include "so_long.h"

# define STRAWBERRY_ASSET	0xd0

void	strawberry_erase(t_game *game, t_img *img);
void	strawberry_update(t_game *game);
void	strawberry_draw(t_game *game, t_img *img);

#endif
