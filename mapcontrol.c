/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:33:46 by sena              #+#    #+#             */
/*   Updated: 2023/03/15 16:25:38 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	component_control(t_win *win, char **map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < win->map->hei && map[y])
	{
		x = -1;
		while (++x < win->map->wid && map[y][x])
		{
			if (!ft_strchr("01PCE", map[y][x]))
				ft_error("Invalid Map Letter!", win);
			else if (map[y][x] == 'P')
				win->map->p_count++;
			else if (map[y][x] == 'C')
				win->map->c_count++;
			else if (map[y][x] == 'E')
				win->map->e_count++;
		}
	}
	if (win->map->p_count != 1)
		ft_error("There is no player or there are more than 1 player!", win);
	if (win->map->c_count < 1)
		ft_error("There is no coin!", win);
	if (win->map->e_count != 1)
		ft_error("Ni ha ha.. There is no exit from here!! You can cry.", win);
}

void	wall_control(t_win *win, char **map)
{
	int	y;
	int	x;
	int	hei;
	int	wid;

	y = 0;
	x = 0;
	hei = win->map->hei;
	wid = win->map->wid;
	while (y < hei && x < wid && map[y][x])
	{
		if (map[y][0] != '1' || map[y][wid - 1] != '1')
			ft_error("Broken Waaaall!", win);
		while ((y == 0 || y == hei - 1) && x < wid)
		{
			if (map[y][x] != '1')
				ft_error("Broken Wall!", win);
			x++;
		}
		x = 0;
		y++;
	}
}

void	map_control(t_win *win, char **map)
{
	win->map->p_count = 0;
	component_control(win, map);
	wall_control(win, map);
}
