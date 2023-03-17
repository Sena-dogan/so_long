/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:34:52 by sena              #+#    #+#             */
/*   Updated: 2023/03/17 19:06:49 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_score(t_win *win)
{
	char	*score;

	score = ft_itoa(win->chr->move_count);
	mlx_string_put(win->mlx, win->id, 62, 62, 0xFF0000, score);
	free(score);
}

void	new_map(t_win *win, char **map, int x, int y)
{
	if (map[y][x] == 'C')
			win->map->c_count--;
	if (map[y][x] == 'E' && win->map->c_count == 0)
	{
		win->chr->move_count++;
		ft_printf(MAG"%d\n"RST, win->chr->move_count);
		ft_key(CLOSE_WIN, win);
	}
	map[win->chr->y][win->chr->x] = '0';
	map[y][x] = 'P';
	win->chr->x = x;
	win->chr->y = y;
	win->chr->move_count++;
	ft_printf(BLU "%d\n" RST, win->chr->move_count);
}

void	edit_map(int keycode, t_win *win, char **map)
{
	int	x;
	int	y;

	find_player(win, map);
	x = win->chr->x;
	y = win->chr->y;
	if (keycode == RIGHT)
		x++;
	else if (keycode == UP)
		y--;
	else if (keycode == DOWN)
		y++;
	else if (keycode == LEFT)
		x--;
	if (map[y][x] != '1' && (map[y][x] != 'E' || win->map->c_count == 0))
	{
		new_map(win, map, x, y);
		render_map(win, map, keycode);
	}		
}
