/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_cloud.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:13:15 by marykman          #+#    #+#             */
/*   Updated: 2023/12/23 23:23:39 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "clouds.h"

t_cloud	random_cloud(int x)
{
	t_cloud	cloud;

	cloud.pos = (t_point){x, ft_randint(0, WIN_HEIGHT)};
	cloud.size = (t_point){ft_randint(60, 150), ft_randint(10, 20)};
	cloud.speed = ft_randint(4, 8);
	return (cloud);
}
