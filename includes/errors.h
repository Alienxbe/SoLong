/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:08:01 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 15:25:41 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define STR_WRONG_ARGUMENT				"Wrong argument given"
# define STR_WRONG_ARGUMENT_COUNT		"Wrong argument count"
# define STR_MALLOC_ERROR				"Malloc error"
# define STR_MAP_WRONG_EXTENSION		\
	"Wrong extension name. It must end with '.ber'"
# define STR_MAP_FILE_NOT_FOUND			"File not found"
# define STR_MAP_CLOSE_ERROR			"Can't close the map file"
# define STR_PARSING_WRONG_LINE_LEN		\
	"The map doesn't have the same number of charater on each line"
# define STR_PARSING_WRONG_CHAR			"Incorrect character found in the map"
# define STR_PARSING_MULTIPLE_PLAYER	"Too many players on the map"
# define STR_PARSING_MULTIPLE_EXIT		"Too many exits on the map"
# define STR_MISSING_PLAYER				"Missing a player on the map"
# define STR_MISSING_EXIT				"Missing an exit on the map"
# define STR_MISSING_COIN				"The map must have at least one coin"
# define STR_UNCLOSED_MAP				"The map must be closed"
# define STR_NO_VALID_PATH				\
	"There must be an open path between the player, the coin(s) and the exit"
# define STR_USAGE_MANDATORY			"Usage: ./so_long <map_file>"
# define STR_USAGE_BONUS				\
	"Usage: ./so_long_bonus <map_file> [dash_count]"

typedef enum e_error
{
	SUCCESS,
	WRONG_ARGUMENT_COUNT,
	WRONG_ARGUMENT,
	MALLOC_ERROR,
	MAP_WRONG_EXTENSION,
	MAP_FILE_NOT_FOUND,
	MAP_CLOSE_ERROR,
	PARSING_WRONG_LINE_LEN,
	PARSING_WRONG_CHAR,
	PARSING_MULTIPLE_PLAYER,
	PARSING_MULTIPLE_EXIT,
	MISSING_PLAYER,
	MISSING_EXIT,
	MISSING_COIN,
	UNCLOSED_MAP,
	NO_VALID_PATH,
	ERROR_LEN
}	t_error;

#endif
