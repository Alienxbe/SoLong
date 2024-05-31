/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smoke.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:45:43 by marykman          #+#    #+#             */
/*   Updated: 2024/04/11 20:46:16 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMOKE_H
# define SMOKE_H

# include "so_long.h"

void	smoke_init(t_game *game);
void	smoke_erase(t_game *game, t_img *img);
void	smoke_update(t_game *game);
void	smoke_draw(t_game *game, t_img *img);

void	smoke_new(t_game *game, t_fpoint pos); // Add a new smoke to the linked list
void	smoke_remove(t_game *game, t_dlist *smoke); // Remove from linked list

#endif
