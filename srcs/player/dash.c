/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:00:10 by marykman          #+#    #+#             */
/*   Updated: 2024/02/06 15:17:50 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "sfe_pixel.h"
#include "sfe_color.h"
#include "player.h"

void	player_update_dash(t_game *game)
{
	if (game->player.djump <= 0 || !game->player.dash)
		return ;
	game->player.djump--;
}
