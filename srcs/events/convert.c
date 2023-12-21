/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:13:05 by marykman          #+#    #+#             */
/*   Updated: 2023/12/20 19:52:50 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sfe_event.h"
#include "events.h"

t_game_keys	sfe_to_game_key(t_sfe_keys key)
{
	static t_sfe_keys	keybind[] = {
		SFE_KEY_LEFT,
		SFE_KEY_RIGHT,
		SFE_KEY_UP,
		SFE_KEY_DOWN,
		SFE_KEY_C,
		SFE_KEY_X
	};
	t_game_keys	i;

	i = -1;
	while (++i < GAME_KEY_LEN)
		if (keybind[i] == key)
			return (i);
	return (GAME_KEY_LEN);
}
