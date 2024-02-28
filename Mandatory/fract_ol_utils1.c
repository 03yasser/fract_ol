/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:34:03 by yboutsli          #+#    #+#             */
/*   Updated: 2024/02/28 13:49:35 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	color_generator(int i, t_fractal *frac)
{
	int	r;
	int	g;
	int	b;

	r = (i * frac->red) % 256;
	g = (i * frac->green) % 256;
	b = (i * frac->blue) % 256;
	return (r << 16 | g << 8 | b);
}

int	key(int keycode, t_fractal *fract)
{
	if (keycode == 53)
		close_win(fract);
	if (keycode == 69)
		fract->iteration += 10;
	else if (keycode == 78 && fract->iteration > 10)
		fract->iteration -= 10;
	else if (keycode == 126)
		fract->shift_y -= (0.5 * fract->zoom);
	else if (keycode == 125)
		fract->shift_y += (0.5 * fract->zoom);
	else if (keycode == 124)
		fract->shift_x -= (0.5 * fract->zoom);
	else if (keycode == 123)
		fract->shift_x += (0.5 * fract->zoom);
	else
		return (0);
	fract_drawing(fract);
	return (0);
}

void	pixel(int x, int y, t_fractal *fract)
{
	t_cmplx	z;
	t_cmplx	c;
	int		i;
	int		color;

	z.r = (scale(x, -2, 2, WIDTH)
			* fract->zoom) + fract->shift_x;
	z.i = (scale(y, 2, -2, HEIGHT)
			* fract->zoom) + fract->shift_y;
	pixel_utils(&c, &z, fract);
	i = -1;
	while (++i < fract->iteration)
	{
		z = cmplx_sum(cmplx_power2(z), c);
		if (sqrt(pow(z.i, 2) + pow(z.r, 2)) > 2)
		{
			color = color_generator(i, fract);
			my_pixel_put(&fract->img, x, y, color);
			return ;
		}
	}
	my_pixel_put(&(fract->img), x, y, 0);
}

int	mouse(int button, int x, int y, t_fractal *fract)
{
	(void)x;
	(void)y;
	if (button == 5)
		fract->zoom *= 1.1;
	else if (button == 4)
		fract->zoom *= 0.9;
	else
		return (0);
	fract_drawing(fract);
	return (0);
}

void	main_utils(t_fractal *fract)
{
	fract_init(fract);
	fract_drawing(fract);
	img_utils(fract);
	mlx_loop(fract->connection);
}
