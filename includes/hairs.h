/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hairs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:01:24 by marykman          #+#    #+#             */
/*   Updated: 2023/12/31 15:30:27 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAIRS_H
# define HAIRS_H

# include "so_long.h"

void	sfe_circfill(t_img img, t_fpoint pos, float r, t_color color);
void	hair_draw(t_img img, t_hair hair);

#endif
