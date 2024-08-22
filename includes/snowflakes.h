/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snowflakes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:19:21 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 16:38:18 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNOWFLAKES_H
# define SNOWFLAKES_H

# include "so_long.h"

# define SNOWFLAKE_COL	0xffffff

void		snowflakes_init(t_game *game);
void		snowflakes_erase(t_game *game, t_img *img);
void		snowflakes_update(t_game *game);
void		snowflakes_draw(t_game *game, t_img *img);

t_snowflake	snowflake_new_random(int x, int max_height);

#endif
