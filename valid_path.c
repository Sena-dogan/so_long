/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:36:21 by sena              #+#    #+#             */
/*   Updated: 2023/03/17 18:14:30 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

char	**array_dup(char **array, int height)
{
	char	**dup;
	int		i;

	i = 0;
	while (array && array[i])
		i++;
	dup = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (array && array[i] && i < height)
	{
		dup[i] = ft_strdup(array[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

void	array_clear(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

int	can_p(char **lines, int x, int y, int dir)
{
	int	res;

	if (x < 0 || y < 0 || !lines[x] || !lines[x][y] || lines[x][y] == '1' ||
		(lines[x][y] == 'E' && dir != NO_DIR))
		return (0);
	if (lines[x][y] == 'P' )
		return (1);
	lines[x][y] = '1';
	res = 0;
	if (dir != DIR_UP)
		res |= can_p(lines, x, y + 1, DIR_DOWN);
	if (dir != DIR_DOWN)
		res |= can_p(lines, x, y - 1, DIR_UP);
	if (dir != DIR_LEFT)
		res |= can_p(lines, x + 1, y, DIR_RIGHT);
	if (dir != DIR_RIGHT)
		res |= can_p(lines, x - 1, y, DIR_LEFT);
	return (res);
}

int	valid_path(t_win *win)
{
	int		i;
	int		j;
	char	**map_dup;

	i = 0;
	map_dup = array_dup(win->map->_map, win->map->hei);
	while (i < win->map->hei && map_dup[i])
	{
		j = 0;
		while (j < win->map->wid && map_dup[i][j])
		{
			if ((map_dup[i][j] == 'C' || map_dup[i][j] == 'E')
				&& !can_p(map_dup, i, j, NO_DIR))
			{
				array_clear(map_dup);
				return (0);
			}
			j++;
		}
		i++;
	}
	array_clear(map_dup);
	return (1);
}
