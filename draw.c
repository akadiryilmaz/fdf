/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayilmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:20:43 by ayilmaz           #+#    #+#             */
/*   Updated: 2022/11/12 20:20:49 by ayilmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	max(double a, double b)
{
	if (a < b)
		return (b);
	return (a);
}

void	draw_point(t_dot start, t_dot finish, t_dot iter, t_fdf *data)
{
	t_dot	point;

	point.x = iter.x + data->shift_x;
	point.y = iter.y + data->shift_y;
	if (start.ex_z != 0 || finish.ex_z != 0)
		mlx_pixel_put(data->mlx, data->win, point.x, point.y, 0xff053);
	else
		mlx_pixel_put(data->mlx, data->win, point.x, point.y, 0xfff053);
	usleep(1);
}

void	draw_line(t_dot start, t_dot finish, t_fdf *data)
{
	double	step_x;
	double	step_y;
	double	pisagor;
	t_dot	iter;

	iter.x = start.x;
	iter.y = start.y;
	pisagor = sqrt(pow((start.x - finish.x), 2) + pow((start.y - finish.y), 2));
	step_x = (start.x - finish.x) / pisagor;
	step_y = (start.y - finish.y) / pisagor;
	while ((int)iter.x != (int)finish.x || (int)iter.y != (int)finish.y)
	{
		if ((int)iter.x != (int)finish.x)
			iter.x -= step_x;
		if ((int)iter.y != (int)finish.y)
			iter.y -= step_y;
		draw_point(start, finish, iter, data);
	}
}

void	draw_all_line(t_fdf *data)
{
	int		idx_x;
	int		idx_y;
	t_dot	start_dot;
	t_dot	finish_dot;

	idx_x = -1;
	while (++idx_x < data->x_d)
	{
		idx_y = -1;
		while (++idx_y < data->y_d)
		{
			start_dot = data->map[idx_y][idx_x];
			if (1 != data->map[idx_y][idx_x].end)
			{
				finish_dot = data->map[idx_y][idx_x + 1];
				draw_line(start_dot, finish_dot, data);
			}
			if (idx_y != data->y_d - 1)
			{
				finish_dot = data->map[idx_y + 1][idx_x];
				draw_line(start_dot, finish_dot, data);
			}
		}
	}
}
