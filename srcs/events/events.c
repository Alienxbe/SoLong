/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:35:19 by marykman          #+#    #+#             */
/*   Updated: 2023/12/20 19:53:06 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_event.h"
#include "sc_main.h"
#include "events.h"

static void	update_game_keys(int key, t_sc_main *sc, t_bool value)
{
	t_game_keys	game_key;

	game_key = sfe_to_game_key(key);
	if (game_key < GAME_KEY_LEN)
		sc->game->active_keys[game_key] = value;
}

static int	on_key_down(int key, t_sc_main *sc)
{
	if (key == SFE_KEY_ESC)
		sc->running = false;
	update_game_keys(key, sc, true);
	return (1);
}

static int	on_key_up(int key, t_sc_main *sc)
{
	update_game_keys(key, sc, false);
	return (1);
}

void	events_init(t_sfe *sfe, t_sc_main *sc)
{
	sfe_hook_on_keydown(sfe->win, &on_key_down, sc);
	sfe_hook_on_keyup(sfe->win, &on_key_up, sc);
}
