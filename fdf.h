/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayilmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:20:58 by ayilmaz           #+#    #+#             */
/*   Updated: 2022/11/12 20:21:00 by ayilmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "utils/get_next_line.h"
# include "utils/libft.h"
# include "utils/ft_printf.h"
# include <string.h>
# define WIDHT 4000
# define HEIGHT 2000
# define ON_DESTROY 17
# define ON_KEYPRESS 2
# define PI 3.14159

typedef struct s_dot
{
	double		x;
	double		y;
	double		z;
	double		ex_z;
	int			end;
}	t_dot;

typedef struct s_fdf
{
	double	rotate;
	double	alt;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	rad;
	int		x_d;
	int		y_d;
	void	*mlx;
	void	*win;
	t_dot	**map;
	char	**z_var;
	char	**text;
}	t_fdf;

void	filler(t_fdf *data, int k, int i);
void	mlx_events(t_fdf *data);
int		close_win(t_fdf *data);
int		key_hook(int key, t_fdf *data);
int		control_map(char *line);
int		ft_error(int err_num);
void	assign_values(t_fdf *data, char **av, int i);
void	mem_allocation(t_fdf *data, char **av, int i, int k);
void	filler(t_fdf *data, int k, int i);
void	rotator(t_fdf *data, int i, int j);
void	draw_all_line(t_fdf *data);
void	design_window(t_fdf *data);
void	draw_line(t_dot start, t_dot finish, t_fdf *data);
#endif
