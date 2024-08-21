/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:06:23 by marykman          #+#    #+#             */
/*   Updated: 2024/08/21 16:27:09 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include "ft_string.h"
#include "get_next_line.h"
#include "parsing.h"

#include <stdio.h>
static t_error	parse_line(t_map *map, t_list **lines, char *line)
{
	t_error	ret;
	t_list	*lst;
	int		*content;

	if (!line)
		return (MALLOC_ERROR);
	if (!map->size.y)
		map->size.x = ft_strlen(line) / PARSING_MODE;
	if (map->size.x != (int)ft_strlen(line) / PARSING_MODE || map->size.x % PARSING_MODE || !*line)
		return (PARSING_WRONG_LINE_LEN);
	ret = parse_content(map, &content, line);
	if (ret)
		return (ret);
	lst = ft_lstnew(content);
	if (!lst)
		return (MALLOC_ERROR);
	ft_lstadd_back(lines, lst);
	map->size.y++;
	return (SUCCESS);
}

static t_error	join_list(t_map *map, t_list *lines, t_error ret)
{
	int	i;

	if (ret)
		return (ret);
	map->tab = malloc(sizeof(*map->tab) * map->size.y);
	if (!map->tab)
		return (MALLOC_ERROR);
	i = 0;
	while (lines)
	{
		map->tab[i] = lines->content;
		lines = lines->next;
		i++;
	}
	return (SUCCESS);
}

t_error	parse_map(t_map *map, int fd)
{
	t_error	ret;
	t_list	*lines;
	char	*line;
	int		gnl;

	lines = NULL;
	gnl = 1;
	ret = SUCCESS;
	while (gnl > 0 && !ret)
	{
		gnl = get_next_line(fd, &line);
		ret = parse_line(map, &lines, line);
		free(line);
	}
	ret = join_list(map, lines, ret);
	if (ret)
		ft_lstclear(&lines, &free);
	else
		ft_lstclear(&lines, NULL);
	return (ret);
}
