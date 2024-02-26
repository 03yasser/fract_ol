/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:12:49 by yboutsli          #+#    #+#             */
/*   Updated: 2024/02/26 20:54:53 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!*s1 || !*s2)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	init_utils(t_fractal *fract)
{
	fract->escape_value = 2;
	fract->iteration = 100;
	fract->shift_x = 0;
	fract->shift_y = 0;
	fract->zoom = 1;
}

int	fract_init(t_fractal *fract)
{
	init_utils(fract);
	fract->connection = mlx_init();
	if (!fract->connection)
		return (0);
	fract->win = mlx_new_window(fract->connection, WIDTH, HEIGHT, fract->name);
	if (!fract->win)
		exit(1);
	fract->img.img_p = mlx_new_image(fract->connection, WIDTH, HEIGHT);
	if (!fract->img.img_p)
	{
		mlx_destroy_window(fract->win, fract->win);
		exit(1);
	}
	fract->img.pxl_p = mlx_get_data_addr(fract->img.img_p,
			&fract->img.bits_per_pixel, &fract->img.line_len,
			&fract->img.endian);
	fract->red = 3;
	fract->green = 7;
	fract->blue = 10;
	return (1);
}

void	fract_drawing(t_fractal *fract)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pixel(x, y, fract);
		}
	}
	mlx_put_image_to_window(fract->connection, fract->win,
		fract->img.img_p, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fractal	fract;

	if (HEIGHT <= 0 || WIDTH <= 0 || WIDTH > 2560 || HEIGHT > 1395)
	{
		write(2, ERROR1, 22);
		exit(1);
	}
	if (argc == 2 && (!ft_strcmp(argv[1], "mandelbrot")
			|| (argc == 4 && !ft_strcmp(argv[1], "julia"))))
	{
		fract.name = argv[1];
		if (!ft_strcmp(fract.name, "julia"))
		{
			fract.j_r = double_atoi(argv[2]);
			fract.j_i = double_atoi(argv[3]);
		}
		main_utils(&fract);
	}
	else
	{
		write(2, ERROR, 57);
		exit(1);
	}
	exit(0);
}
