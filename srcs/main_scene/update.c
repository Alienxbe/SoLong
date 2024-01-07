/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:31:23 by marykman          #+#    #+#             */
/*   Updated: 2024/01/07 14:35:06 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "t_sfe.h"
#include "sfe_pixel.h"
#include "sc_main.h"
#include "player.h"
#include "snowflakes.h"
#include "clouds.h"

void	main_update(t_sc_main *sc)
{
	player_update(sc->game);
	clouds_update(sc->game);
	snowflakes_update(sc->game);
}

int	sc_main_update(t_sc_main *sc)
{
	main_erase(sc);
	main_update(sc);
	main_draw(sc);
	ft_printf("FPS: %d\n", sc->sfe->fps);
	return (sc->running);
}
