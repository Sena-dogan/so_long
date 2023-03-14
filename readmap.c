/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:08:40 by egun              #+#    #+#             */
/*   Updated: 2022/07/01 22:10:59 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
#include <stdio.h>

void	ft_error(char	*msg, t_win *win)
{

	ft_printf(RED "%s\n" RST, msg);
	ft_printf("Error\n");
	close_frame(win);
}

void	map_size(char *path, t_win *win)
{
	int		fd;
	char	*line;
	char	*trim_line;

	win->map->hei = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("Invalid ber", win);
	line = get_next_line(fd);
	win->map->wid = (int)ft_strlen(line) - 1;
	if (line == 0)
		ft_error("Invalid map size", win);
	while (line && ++win->map->hei)
	{
		trim_line = ft_strtrim(line, "\n");
		if (trim_line && win->map->wid != (int)ft_strlen(trim_line))
		{
			free(trim_line);
			free(line);
			ft_error("wrong map", win);
		}
		free(trim_line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	read_map(t_win *win, char *path)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("Invalid ber", win);
	line = get_next_line(fd);
	win->map->_map = ft_calloc(win->map->hei, sizeof(char *));
	while (line)
	{
		win->map->_map[i] = ft_calloc(win->map->wid, 1);
		ft_strlcpy(win->map->_map[i], line, win->map->wid + 1);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
