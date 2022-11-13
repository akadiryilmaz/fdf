/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayilmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:21:21 by ayilmaz           #+#    #+#             */
/*   Updated: 2022/11/12 20:21:22 by ayilmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_events(t_fdf *data)
{
	mlx_hook(data->win, ON_KEYPRESS, 0, &key_hook, data);
	mlx_hook(data->win, ON_DESTROY, 0, &close_win, data);
}

int	key_hook(int key, t_fdf *data)
{
	mlx_clear_window(data->mlx, data->win);
	if (key == 126)
		data->zoom += 1;
	else if (key == 125)
		data->zoom -= 0.5;
	else if (key == 123)
		data->alt -= 0.1;
	else if (key == 124)
		data->alt += 0.1;
	else if (key == 49)
		data->rad += 0.1;
	else if (key == 0)
		data->shift_x -= WIDHT / 100;
	else if (key == 2)
		data->shift_x += WIDHT / 100;
	else if (key == 1)
		data->shift_y += HEIGHT / 100;
	else if (key == 13)
		data->shift_y -= HEIGHT / 100;
	else if (key == 53)
		close_win(data);
	assign_values(data, data->text, 0);
	design_window(data);
	return (0);
}

int	close_win(t_fdf *data)
{
	free (data->map);
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
	return (0);
}

int	control_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if ((line[i] <= '0' || line[i] >= '9') && (line[i] != ' '
				|| line[i] == '-'))
			return (0);
	}
	return (1);
}
