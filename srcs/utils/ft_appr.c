/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:38:33 by marykman          #+#    #+#             */
/*   Updated: 2023/12/29 23:58:39 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

float	ft_appr(float val, float target, float amount)
{
	if (val > target)
		return (ft_maxfloat(val - amount, target));
	return (ft_minfloat(val + amount, target));
}
