/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:34:25 by sena              #+#    #+#             */
/*   Updated: 2023/03/17 19:19:49 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_and_struct(t_win *win)
{
	int	i;

	i = -1;
	while (++i < win->map->hei)
	{
		free(win->map->_map[i]);
	}
	free(win->map->_map);
}

int	close_frame(t_win *win)
{
	if (win->chr->chr_up && win->chr->chr_down
		&& win->chr->chr_r && win->chr->chr_l && win->bg)
	{
		if (win->coin && win->exit && win->wall && win->id)
		{
			mlx_destroy_image(win->mlx, win->chr->chr_up);
			mlx_destroy_image(win->mlx, win->chr->chr_down);
			mlx_destroy_image(win->mlx, win->chr->chr_r);
			mlx_destroy_image(win->mlx, win->chr->chr_l);
			mlx_destroy_image(win->mlx, win->bg);
			mlx_destroy_image(win->mlx, win->coin);
			mlx_destroy_image(win->mlx, win->exit);
			mlx_destroy_image(win->mlx, win->wall);
			mlx_destroy_window(win->mlx, win->id);
		}
	}
	free_map_and_struct(win);
	exit (1);
	return (1);
}

int	ft_key(int keycode, t_win *win)
{
	if (keycode == CLOSE_WIN)
		close_frame(win);
	else if (keycode == RIGHT || keycode == LEFT
		|| keycode == UP || keycode == DOWN)
		edit_map(keycode, win, win->map->_map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	*win;

	if (argc == 2 && !ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 5))
	{
		win = ft_calloc(1, sizeof(t_win));
		win->map = ft_calloc(sizeof(t_map), 1);
		win->chr = ft_calloc(1, sizeof(t_chr));
		win->mlx = mlx_init();
		map_size(argv[1], win);
		win->id = mlx_new_window(win->mlx,
				64 * win->map->wid, 64 * win->map->hei, "BumbleBee");
		read_map(win, argv[1]);
		map_control(win, win->map->_map);
		if (!valid_path(win))
			ft_error("Invalid path.\nError\n", win);
		mlx_hook(win->id, 2, 1L << 0, ft_key, win);
		mlx_hook(win->id, 17, 0, close_frame, win);
		render_map(win, win->map->_map, 13);
		mlx_loop(win->mlx);
	}
	else
		ft_printf("Invalid input.\nError\n");
	return (0);
}
