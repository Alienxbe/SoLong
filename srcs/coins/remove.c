/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:21:28 by marykman          #+#    #+#             */
/*   Updated: 2024/06/14 21:32:08 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "coins.h"

void	coin_remove(t_dlist **list, t_dlist *elem)
{
	if (!elem->previous)
		*list = elem->next;
	ft_dlstdelone(ft_dlstremove(elem), &free);
}