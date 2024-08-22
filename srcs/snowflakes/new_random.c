/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_random.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:44:54 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 16:39:52 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "snowflakes.h"

t_snowflake	snowflake_new_random(int x, int max_height)
{
	t_snowflake	sf;

	sf = (t_snowflake){0};
	sf.pos = (t_fpoint){x, ft_randint(-20, max_height)};
	sf.size = ft_randint(4, 10);
	sf.speed = ft_randint(2, 8);
	sf.frq = (float)ft_randint(2, 6) / 100;
	sf.ampl = ft_randint(2, 4);
	return (sf);
}
