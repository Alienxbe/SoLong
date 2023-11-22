/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:28:58 by marykman          #+#    #+#             */
/*   Updated: 2023/11/22 23:48:34 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe.h"
#include "sfe_event.h"
#include "sc_main.h"
#include "ft_printf.h"
#include "so_long.h"

static int	on_key_down(int key, t_sc_main *sc)
{
	if (key == 53)
		sc->running = false;
	ft_printf("Key pressed: %d\n", key);
	return (1);
}

static void	init_window(t_sfe **sfe, t_sc_main *sc)
{
	*sfe = sfe_init(WIN_NAME, new_point(WIN_DIM));
	sfe_set_max_fps(*sfe, 120);

	sc->scene = sfe_new_scene(*sfe, sc);
	sc->scene.f_init = &sc_main_init;
	sc->scene.f_update = &sc_main_update;
	sc->scene.f_destroy = &sc_main_destroy;
	sc->sfe = *sfe;

	sfe_set_active_scene(*sfe, &sc->scene);
	sfe_hook(*sfe, ON_KEYDOWN, &on_key_down, sc);
}

int	main(void)
{
	t_sfe		*sfe;
	t_sc_main	sc;

	init_window(&sfe, &sc);
	sfe_loop(sfe);
	return (0);
}
