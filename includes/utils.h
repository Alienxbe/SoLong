/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:11:46 by marykman          #+#    #+#             */
/*   Updated: 2024/08/21 18:17:40 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "so_long.h"

float	ft_appr(float val, float target, float amount);
float	ft_abs(float a);
t_point	pixel_to_map_pos(t_fpoint pos);

#endif
