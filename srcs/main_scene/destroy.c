/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:18:20 by marykman          #+#    #+#             */
/*   Updated: 2023/12/18 17:09:51 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "t_sfe.h"
#include "sc_main.h"

int		sc_main_destroy(t_sc_main *sc)
{
	size_t	i;

	i = -1;
	while (sc->game->assets[++i].img)
		sfe_image_destroy(sc->sfe->mlx_ptr, sc->game->assets[i]);
	free(sc->game->assets);
	return (0);
}
