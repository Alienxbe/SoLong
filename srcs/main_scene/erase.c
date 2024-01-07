/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:21:37 by marykman          #+#    #+#             */
/*   Updated: 2024/01/07 14:30:58 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sc_main.h"
#include "player.h"
#include "snowflakes.h"
#include "clouds.h"

void	main_erase(t_sc_main *sc)
{
	player_erase(sc->game, sc->scene.img);
	snowflakes_erase(sc->game, sc->scene.img);
	clouds_erase(sc->game, sc->scene.img);
}
