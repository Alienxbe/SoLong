/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_random.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:13:15 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 16:40:08 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "clouds.h"

t_cloud	clouds_new_random(int x, int max_height)
{
	t_cloud	cloud;

	cloud.pos = (t_point){x, ft_randint(0, max_height)};
	cloud.size = (t_point){ft_randint(130, 300), ft_randint(20, 40)};
	cloud.speed = ft_randint(4, 8);
	return (cloud);
}
