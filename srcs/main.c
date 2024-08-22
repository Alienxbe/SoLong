/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:28:58 by marykman          #+#    #+#             */
/*   Updated: 2024/08/22 15:17:10 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "ft_ctype.h"
#include "ft_string.h"
#include "ft_math.h"
#include "sfe.h"
#include "so_long.h"
#include "sc_main.h"
#include "events.h"
#include "parsing.h"
#include "stats_bar.h"

static void	init_window(t_sfe **sfe, t_sc_main *sc)
{
	t_point	win_size;

	win_size = (t_point){sc->game->map.pixel_size.x,
		sc->game->map.pixel_size.y + STATS_BAR_SIZE};
	*sfe = sfe_init(WIN_NAME, win_size);
	sfe_set_max_fps(*sfe, 60);
	sc->scene = sfe_new_scene(*sfe, sc);
	sc->scene.f_init = &sc_main_init;
	sc->scene.f_update = &sc_main_update;
	sc->scene.f_destroy = &sc_main_destroy;
	sc->sfe = *sfe;
	sfe_set_active_scene(*sfe, &sc->scene);
	events_init(*sfe, sc);
}

static t_error	bonus_args(int argc, char **argv, t_game *game)
{
	if (argc != 2 && argc != 3)
		return (WRONG_ARGUMENT_COUNT);
	if (argc == 3)
	{
		if (!ft_isnumber(argv[2]))
			return (WRONG_ARGUMENT);
		game->player.max_djump = ft_atoi(argv[2]);
	}
	return (SUCCESS);
}

static int	print_error(t_error error)
{
	char	*msg[ERROR_LEN];
	char	*usage;

	msg[WRONG_ARGUMENT] = STR_WRONG_ARGUMENT;
	msg[WRONG_ARGUMENT_COUNT] = STR_WRONG_ARGUMENT_COUNT;
	msg[MALLOC_ERROR] = STR_MALLOC_ERROR;
	msg[MAP_WRONG_EXTENSION] = STR_MAP_WRONG_EXTENSION;
	msg[MAP_FILE_NOT_FOUND] = STR_MAP_FILE_NOT_FOUND;
	msg[MAP_CLOSE_ERROR] = STR_MAP_CLOSE_ERROR;
	msg[PARSING_WRONG_LINE_LEN] = STR_PARSING_WRONG_LINE_LEN;
	msg[PARSING_WRONG_CHAR] = STR_PARSING_WRONG_CHAR;
	msg[PARSING_MULTIPLE_PLAYER] = STR_PARSING_MULTIPLE_PLAYER;
	msg[PARSING_MULTIPLE_EXIT] = STR_PARSING_MULTIPLE_EXIT;
	msg[MISSING_PLAYER] = STR_MISSING_PLAYER;
	msg[MISSING_EXIT] = STR_MISSING_EXIT;
	msg[MISSING_COIN] = STR_MISSING_COIN;
	msg[UNCLOSED_MAP] = STR_UNCLOSED_MAP;
	msg[NO_VALID_PATH] = STR_NO_VALID_PATH;
	usage = STR_USAGE_MANDATORY;
	if (PARSING_MODE == 2)
		usage = STR_USAGE_BONUS;
	ft_fprintf(STDERR_FILENO, "Error: %s\n%s\n", msg[error], usage);
	return (1);
}

int	main(int argc, char **argv)
{
	t_sfe		*sfe;
	t_sc_main	sc;
	t_game		game;
	t_error		error;

	sc = (t_sc_main){0};
	game = (t_game){0};
	sc.game = &game;
	error = SUCCESS;
	if (PARSING_MODE == 1 && argc != 2)
		error = WRONG_ARGUMENT_COUNT;
	else
		error = bonus_args(argc, argv, &game);
	if (!error)
		error = parsing(&game.map, argv[1]);
	if (error)
		return (print_error(error));
	init_window(&sfe, &sc);
	ft_randinit();
	sfe_loop(sfe);
	return (0);
}
