/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayilmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:21:31 by ayilmaz           #+#    #+#             */
/*   Updated: 2022/11/12 20:21:33 by ayilmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	design_window(t_fdf *data)
{
	int		idx_x;
	int		idx_y;
	double	x;
	double	y;
	double	z;

	idx_x = -1;
	while (++idx_x < data->x_d)
	{
		idx_y = -1;
		while (++idx_y < data->y_d)
		{
			z = data->map[idx_y][idx_x].z;
			rotator(data, idx_y, idx_x);
			x = data->map[idx_y][idx_x].x * data->zoom;
			y = data->map[idx_y][idx_x].y * data->zoom;
			data->map[idx_y][idx_x].x *= data->zoom;
			data->map[idx_y][idx_x].y *= data->zoom;
		}
	}
	draw_all_line(data);
}

void	filler(t_fdf *data, int k, int i)
{
	data->map[i][k].x = k;
	data->map[i][k].y = i;
	data->map[i][k].z = ft_atoi(data->z_var[k]) * data->alt;
	data->map[i][k].ex_z = ft_atoi(data->z_var[k]);
	data->map[i][k].end = 0;
	free(data->z_var[k]);
}

void	assign_values(t_fdf *data, char **av, int i)
{
	int		k;
	int		fd;
	char	*read;

	fd = open(av[1], O_RDWR);
	read = get_next_line(fd);
	while (read)
	{
		k = -1;
		data->z_var = ft_split(read, ' ');
		while (data->z_var[++k])
		{
			filler(data, k, i);
		}
		if (i != 0 && data->x_d != k)
			perror("Error");
		data->x_d = k;
		data->map[i++][k - 1].end = 1;
		free(data->z_var);
		free(read);
		read = get_next_line(fd);
	}
	free(read);
}

void	mem_allocation(t_fdf *data, char **av, int i, int k)
{
	int		fd;
	char	*read;

	fd = open(av[1], O_RDWR);
	read = get_next_line(fd);
	while (read)
	{
		if (control_map(read))
			perror("Error");
		k = -1;
		data->z_var = ft_split(read, ' ');
		while (data->z_var[++k])
			free(data->z_var[k]);
		free(data->z_var);
		free(read);
		read = get_next_line(fd);
		i++;
	}
	free(read);
	close(fd);
	data->y_d = i;
	data->map = (t_dot **)malloc(sizeof(t_dot *) * (i + 1));
	data->map[i] = NULL;
	while (--i >= 0)
		data->map[i] = (t_dot *)malloc(sizeof(t_dot) * (k + 1));
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	(void)ac;
	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->shift_x = 100;
	data->shift_y = 100;
	data->text = av;
	data->alt = -0.3;
	data->rad = 0.3;
	data->zoom = 5;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDHT, HEIGHT, "Fdf42");
	if (data->win == NULL)
		perror("Error");
	mem_allocation(data, av, 0, -1);
	assign_values(data, av, 0);
	design_window(data);
	mlx_events(data);
	mlx_loop(data->mlx);
}
