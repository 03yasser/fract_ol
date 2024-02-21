/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:12:49 by yboutsli          #+#    #+#             */
/*   Updated: 2024/02/21 21:43:27 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	init_utils(t_fractal *fract)
{
	fract->escape_value = 2;
	fract->iteration = 100;
	fract->shift_x = 0;
	fract->shift_y = 0;
	fract->left_x = -2;
	fract->right_x = 2;
	fract->top_y = 2;
	fract->bot_y = -2;
	fract->zoom = 1;
}

int	fract_init(t_fractal *fract)
{
	init_utils(fract);
	fract->connection = mlx_init();
	if (!fract->connection)
		return (0);
	fract->win = mlx_new_window(fract->connection, WIDTH, HEIGHT, fract-> name);
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
	fract->red = 20;
	fract->green = 10;
	fract->blue = 30;
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
			pixel(x, y, fract);
	}
	mlx_put_image_to_window(fract->connection, fract->win,
		fract->img.img_p, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fractal	fract;

	if (argc == 1 || (argc == 2 && (ft_strncmp(argv[1], "mandelbrot", 10)
				&& ft_strncmp(argv[1], "tricorn", 7)))
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 5)))
	{
		write(2, ERROR, 70);
		exit(1);
	}
	if (HEIGHT <= 0 || WIDTH <= 0 || WIDTH > 2560 || HEIGHT > 1395)
	{
		write(2, ERROR1, 22);
		exit(1);
	}
	fract.name = argv[1];
	if (!ft_strncmp(fract.name, "julia", 5))
	{
		fract.j_r = double_atoi(argv[2]);
		fract.j_i = double_atoi(argv[3]);
	}
	fract_init(&fract);
	fract_drawing(&fract);
	img_utils(&fract);
	mlx_loop(fract.connection);
	exit(1);
}
