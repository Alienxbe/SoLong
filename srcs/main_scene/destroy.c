/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:18:20 by marykman          #+#    #+#             */
/*   Updated: 2024/08/21 00:46:42 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "t_sfe.h"
#include "sc_main.h"
#include "sfe_image.h"

int	sc_main_destroy(t_sc_main *sc)
{
	size_t	i;

	i = -1;
	while (sc->game->assets[++i].img)
		sfe_image_destroy(sc->sfe->mlx_ptr, &sc->game->assets[i]);
	free(sc->game->assets);
	ft_dlstclear(&sc->game->map.strawberries, &free);
	ft_dlstclear(&sc->game->map.secret_walls, &free);
	ft_dlstclear(&sc->game->strawberries, &free);
	ft_dlstclear(&sc->game->secret_walls, &free);
	return (0);
}
