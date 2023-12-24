/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_snowflake.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:44:54 by marykman          #+#    #+#             */
/*   Updated: 2023/12/24 14:52:54 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "snowflakes.h"

t_snowflake	random_snowflake(int x)
{
	t_snowflake	sf;

	sf = (t_snowflake){0};
	sf.pos = (t_fpoint){x, ft_randint(-20, WIN_HEIGHT)};
	sf.size = ft_randint(4, 10);
	sf.speed = ft_randint(2, 8);
	sf.frq = (float)ft_randint(2, 6) / 100;
	sf.ampl = ft_randint(2, 4);
	return (sf);
}
