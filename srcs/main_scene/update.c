/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:31:23 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 18:29:02 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_sfe.h"
#include "sfe_pixel.h"
#include "sc_main.h"
#include "player.h"
#include "exit.h"
#include "snowflakes.h"
#include "strawberries.h"
#include "secret_walls.h"
#include "clouds.h"
#include "parsing.h"

void	main_update(t_sc_main *sc)
{
	player_update(sc->game);
	exit_update(sc->game);
	clouds_update(sc->game);
	snowflakes_update(sc->game);
	strawberry_update(sc->game);
	secret_wall_update(sc->game);
}

int	sc_main_update(t_sc_main *sc)
{
	main_erase(sc);
	main_update(sc);
	main_draw(sc);
	return (sc->running);
}
