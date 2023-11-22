/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:33:26 by marykman          #+#    #+#             */
/*   Updated: 2023/11/22 23:49:57 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SC_MAIN_H
# define SC_MAIN_H

# include "t_scene.h"

typedef struct s_sc_main
{
	t_sfe			*sfe;
	t_scene			scene;
	t_img			*assets;
	t_bool			running;
}	t_sc_main;

int		sc_main_init(t_sc_main *sc);
int		sc_main_update(t_sc_main *sc);
int		sc_main_destroy(t_sc_main *sc);

t_img	*sfe_load_sprite_sheet(t_sfe *sfe, char *filename, t_point sprite_size);

#endif