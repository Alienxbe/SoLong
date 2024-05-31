/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:08:01 by marykman          #+#    #+#             */
/*   Updated: 2024/05/31 12:10:58 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum e_error
{
	SUCCESS,
	MALLOC_ERROR,
	MAP_WRONG_EXTENSION,
	MAP_FILE_NOT_FOUND,
	MAP_CLOSE_ERROR,
	PARSING_WRONG_LINE_LEN,
	PARSING_WRONG_CHAR,
	PARSING_MULTIPLE_PLAYER,
	PARSING_COIN_ERROR,
	ERROR_LEN
}	t_error;

#endif
