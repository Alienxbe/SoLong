/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:35:33 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 16:35:49 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "sfe_event.h"

typedef enum e_game_keys
{
	GAME_KEY_LEFT,
	GAME_KEY_RIGHT,
	GAME_KEY_UP,
	GAME_KEY_DOWN,
	GAME_KEY_JUMP,
	GAME_KEY_DASH,
	GAME_KEY_LEN
}	t_game_keys;

t_game_keys	sfe_to_game_key(t_sfe_keys key);

#endif
