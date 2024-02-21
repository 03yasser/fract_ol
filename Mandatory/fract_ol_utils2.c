/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:50:35 by yboutsli          #+#    #+#             */
/*   Updated: 2024/02/21 21:43:58 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	scale(double x, double new_min, double new_max, double old_max)
{
	return (((new_max - new_min) * x) / old_max + new_min);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->pxl_p)) = color;
}

void	pixel_utils(t_cmplx *c, t_cmplx *z, t_fractal *fract)
{
	if (!ft_strncmp(fract->name, "julia", 5))
	{
		c->r = fract->j_r;
		c->i = fract->j_i;
	}
	else
	{
		c->r = z->r;
		c->i = z->i;
	}
}

int	close_win(t_fractal *fract)
{
	mlx_destroy_image(fract->connection, fract->img.img_p);
	mlx_destroy_window(fract->connection, fract->win);
	exit(0);
}

void	img_utils(t_fractal *fract)
{
	mlx_hook(fract->win, 2, 0, key, fract);
	mlx_mouse_hook(fract->win, mouse, fract);
	mlx_hook(fract->win, 17, 0, close_win, fract);
}
