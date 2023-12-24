/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:16:50 by marykman          #+#    #+#             */
/*   Updated: 2023/12/24 15:13:11 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "clouds.h"

void	init_clouds(t_game *game)
{
	size_t	i;

	i = -1;
	while (++i < CLOUD_COUNT)
		game->clouds[i] = random_cloud(ft_randint(-300, WIN_WIDTH));
}
