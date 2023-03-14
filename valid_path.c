#include "so_long.h"
#include <string.h>

char	**array_dup(char **array)
{
    ft_printf("start dup\n");
    char	**dup;
    int		i;

    i = 0;
    while (array && array[i])
        i++;
    dup = (char **)malloc(sizeof(char *) * (i + 1));
    if (!dup)
        return (NULL);
    i = 0;
    ft_printf("start dup while\n");
    while (array && array[i])
    {
        dup[i] = ft_strdup(array[i]);
        ft_printf("dup[%d]: %s\n", i, dup[i]);
        i++;
    }
    ft_printf("end dup while\n");
    dup[i] = NULL;
    ft_printf("dup: %s\na", dup[0]);
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

int can_p(char **lines, int x, int y, int dir) {
    char **map_dup;

    if (dir == 0)
	{
		map_dup = array_dup(lines);
		dir = can_p(map_dup, x, y, 5);
		return (dir);
	}

    if (x < 0 || y < 0 || !lines[x] || !lines[x][y] || lines[x][y] == '1')
        return 0;
    if (lines[x][y] == 'P')
        return 1;
    lines[x][y] = '1';
    int res = 0;
    if (dir != 2)
        res |= can_p(lines, x, y + 1, 1);
    if (dir != 1)
        res |= can_p(lines, x, y - 1, 2);
    if (dir != 4)
        res |= can_p(lines, x + 1, y, 3);
    if (dir != 3)
        res |= can_p(lines, x - 1, y, 4);
    return res;
}


int	valid_path(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	while (i < win->map->hei && win->map->_map[i])
	{
		j = 0;
		while (j < win->map->wid && win->map->_map[i][j])
		{
            ft_printf("i: %d, j: %d, char: %c\n", i, j, win->map->_map[i][j]);
			if ((win->map->_map[i][j] == 'C' || win->map->_map[i][j] == 'E')
				&& !can_p(win->map->_map, i, j, 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}