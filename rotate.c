/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayilmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:21:39 by ayilmaz           #+#    #+#             */
/*   Updated: 2022/11/12 20:21:42 by ayilmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_z(t_dot *dot, t_fdf *data)
{
	double	nx;
	double	ny;

	nx = dot[0].x;
	ny = dot[0].y;
	dot[0].x = nx * cos(data->rad) - ny * sin(data->rad);
	dot[0].y = nx * sin(data->rad) + ny * cos(data->rad);
}

static void	rotate_x(t_dot *dot, t_fdf *data)
{
	double	ny;
	double	nz;

	ny = dot[0].y;
	nz = dot[0].z;
	dot[0].y = ny * cos(data->rad) + nz * sin(data->rad);
	dot[0].z = -ny * sin(data->rad) + nz * cos(data->rad);
}

static void	rotate_y(t_dot *dot, t_fdf *data)
{
	double	nx;
	double	nz;

	nx = dot[0].x;
	nz = dot[0].z;
	dot[0].x = nx * cos(data->rad) + nz * sin(data->rad);
	dot[0].z = -nx * sin(data->rad) + nz * cos(data->rad);
}

void	rotator(t_fdf *data, int i, int j)
{
	rotate_z(&data->map[i][j], data);
	rotate_x(&data->map[i][j], data);
	rotate_y(&data->map[i][j], data);
}
