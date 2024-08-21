/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 01:22:55 by marykman          #+#    #+#             */
/*   Updated: 2024/08/21 02:14:37 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include "so_long.h"

# define EXIT_ASSET	0xc0

int		exit_init(t_game *game, t_point pos);
void	exit_erase(t_game *game, t_img *img);
void	exit_update(t_game *game);
void	exit_draw(t_game *game, t_img *img);

#endif
