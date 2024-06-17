/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:28:58 by marykman          #+#    #+#             */
/*   Updated: 2024/06/14 21:27:46 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "sfe.h"
#include "so_long.h"
#include "sc_main.h"
#include "events.h"
#include "parsing.h"
#include "ft_math.h"

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

#include "stdlib.h"

int	main(int argc, char **argv)
{
	t_sfe		*sfe;
	t_sc_main	sc;
	t_game		game;

	sc = (t_sc_main){0};
	game = (t_game){0};
	sc.game = &game;
	if (argc != 2 || parsing(&game.map, argv[1]))
		return (1);
	init_window(&sfe, &sc);
	ft_randinit();
	sfe_loop(sfe);
	return (0);
}
