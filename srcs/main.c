/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:28:58 by marykman          #+#    #+#             */
/*   Updated: 2023/12/18 17:43:24 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "sfe.h"
#include "so_long.h"
#include "sc_main.h"
#include "events.h"
#include "parsing.h"

static void	init_window(t_sfe **sfe, t_sc_main *sc)
{
	*sfe = sfe_init(WIN_NAME, new_point(WIN_DIM));
	sfe_set_max_fps(*sfe, 60);

	sc->scene = sfe_new_scene(*sfe, sc);
	sc->scene.f_init = &sc_main_init;
	sc->scene.f_update = &sc_main_update;
	sc->scene.f_destroy = &sc_main_destroy;
	sc->sfe = *sfe;

	sfe_set_active_scene(*sfe, &sc->scene);
	events_init(*sfe, sc);
}

int	main(void)
{
	t_sfe		*sfe;
	t_sc_main	sc;
	t_game		game;


	sc = (t_sc_main){0};
	game = (t_game){0};
	sc.game = &game;
	if (parsing(&game.map, "maps/celeste0.ber"))
		return (1);
	init_window(&sfe, &sc);
	sfe_loop(sfe);
	return (0);
}
