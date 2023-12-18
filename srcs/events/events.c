/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:35:19 by marykman          #+#    #+#             */
/*   Updated: 2023/12/18 18:22:21 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_event.h"
#include "sc_main.h"
#include "events.h"

static int	on_key_down(int key, t_sc_main *sc)
{
	if (key == SFE_KEY_ESC)
		sc->running = false;
	if (key == SFE_KEY_LEFT)
		sc->game->player.move_left = true;
	return (1);
}

static int	on_key_up(int key, t_sc_main *sc)
{
	if (key == SFE_KEY_LEFT)
		sc->game->player.move_left = false;
	return (1);
}

void	events_init(t_sfe *sfe, t_sc_main *sc)
{
	sfe_hook_on_keydown(sfe->win, &on_key_down, sc);
	sfe_hook_on_keyup(sfe->win, &on_key_up, sc);
}
