/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snowflakes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:19:21 by marykman          #+#    #+#             */
/*   Updated: 2023/12/24 14:15:48 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNOWFLAKES_H
# define SNOWFLAKES_H

# include "so_long.h"

void	snowflakes_init(t_game *game);
void	snowflakes_update(t_game *game, t_img img);
void	snowflakes_draw(t_game *game, t_img img);

t_snowflake	random_snowflake(int x);


#endif
