/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:12:56 by yboutsli          #+#    #+#             */
/*   Updated: 2024/02/21 18:13:58 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol_bonus.h"

t_cmplx	cmplx_sum(t_cmplx z1, t_cmplx z2)
{
	t_cmplx	x;

	x.r = z1.r + z2.r;
	x.i = z1.i + z2.i;
	return (x);
}

t_cmplx	cmplx_power2(t_cmplx z1)
{
	t_cmplx	x;

	x.r = pow(z1.r, 2) - pow(z1.i, 2);
	x.i = 2 * z1.r * z1.i;
	return (x);
}

double	double_atoi(char *s)
{
	long	part1;
	double	part2;
	double	pow;
	int		sign;

	part1 = 0;
	part2 = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		s++;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		part1 = (part1 * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		part2 = part2 + (*s++ - 48) * pow;
	}
	return ((part1 + part2) * sign);
}

t_cmplx	cmplx_conj(t_cmplx z)
{
	t_cmplx	x;

	x.r = z.r;
	x.i = -1 * z.i;
	return (x);
}
