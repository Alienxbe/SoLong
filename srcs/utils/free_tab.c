/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:07:14 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 16:21:39 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

void	free_tab(int **tab, int max)
{
	int	i;

	i = -1;
	while (++i < max)
		free(tab[i]);
	free(tab);
}
