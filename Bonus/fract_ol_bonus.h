/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:11:33 by yboutsli          #+#    #+#             */
/*   Updated: 2024/02/21 21:46:17 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_BONUS_H
# define FRACT_OL_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h> 
# define HEIGHT 100
# define WIDTH 1500
# define ERROR1 "HEIGHT or WIDTH error\n"
# define ERROR "ERROR enter : <mandelbrot> or <julia 'real' 'imagianry'> \
or <tricorn>\n"

typedef struct s_img
{
	void	*img_p;
	char	*pxl_p;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_cmplx
{
	double	r;
	double	i;
}	t_cmplx;
typedef struct s_fractal
{
	void	*connection;
	void	*win;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	j_r;
	double	j_i;
	double	left_x;
	double	right_x;
	double	top_y;
	double	bot_y;
	int		escape_value;
	int		iteration;
	int		red;
	int		green;
	int		blue;
	t_img	img;
	char	*name;
}				t_fractal;
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			fract_init(t_fractal *fract);
t_cmplx		cmplx_power2(t_cmplx z1);
t_cmplx		cmplx_sum(t_cmplx z1, t_cmplx z2);
double		double_atoi(char *s);
void		pixel(int x, int y, t_fractal *fract);
void		fract_drawing(t_fractal *fract);
int			mouse(int button, int x, int y, t_fractal *fract);
int			key(int keycode, t_fractal *fract);
void		img_utils(t_fractal *fract);
void		my_pixel_put(t_img *img, int x, int y, int color);
void		pixel_utils(t_cmplx *c, t_cmplx *z, t_fractal *fract);
int			close_win(t_fractal *fract);
double		scale(double x, double new_min, double new_max, double old_max);
t_cmplx		cmplx_conj(t_cmplx z);
#endif