/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:36:00 by sena              #+#    #+#             */
/*   Updated: 2023/03/15 16:51:04 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"
# include "./mlx/mlx.h"
# include "./gnl/get_next_line.h"

enum{
	LEFT,
	DOWN,
	RIGHT,
	UP = 13,
	CLOSE_WIN = 53
};
typedef struct s_map
{
	int			wid;
	int			hei;
	char		**_map;
	int			p_count;
	int			c_count;
	int			e_count;
}	t_map;

typedef struct s_chr
{
	void	*chr_r;
	void	*chr_l;
	void	*chr_up;
	void	*chr_down;
	int		move_count;
	int		size;
	int		x;
	int		y;
	int		dir;
}	t_chr;

typedef struct s_win
{
	t_map	*map;
	t_chr	*chr;
	void	*mlx;
	void	*win;
	void	*bg;
	void	*wall;
	void	*exit;
	void	*coin;
}	t_win;

void	map_size(char *path, t_win *map);
void	read_map(t_win *win, char *path);
void	map_control(t_win	*win, char	**map);
void	render_map(t_win *win, char	**map, int move);
int		ft_key(int keycode, t_win *win);
void	edit_map(int keycode, t_win *win, char **map);
void	find_player(t_win *win, char **map);
void	put_score(t_win *win);
void	wall_control(t_win *win, char **map);
void	component_control(t_win *win, char **map);
int		close_frame(t_win *win);
void	ft_error(char	*msg, t_win *win);
int		valid_path(t_win *win);
#endif
