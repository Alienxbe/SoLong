/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:21:37 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 15:29:38 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sc_main.h"
#include "player.h"
#include "exit.h"
#include "strawberries.h"
#include "secret_walls.h"
#include "snowflakes.h"
#include "clouds.h"

void	main_erase(t_sc_main *sc)
{
	player_erase(sc->game, sc->scene.img);
	exit_erase(sc->game, sc->scene.img);
	strawberry_erase(sc->game, sc->scene.img);
	secret_wall_erase(sc->game, sc->scene.img);
	snowflakes_erase(sc->game, sc->scene.img);
	clouds_erase(sc->game, sc->scene.img);
}
