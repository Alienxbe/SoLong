/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:07:01 by marykman          #+#    #+#             */
/*   Updated: 2024/06/12 19:22:38 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COINS_H
# define COINS_H

# include "ft_dlist.h"
# include "ft_point.h"
# include "errors.h"

t_error	coin_add(t_dlist **list, t_point pos);
void	coin_remove(t_dlist **list, t_dlist *elem);

#endif
