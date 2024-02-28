/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_utils3_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:50:32 by yboutsli          #+#    #+#             */
/*   Updated: 2024/02/27 21:51:34 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol_bonus.h"

int	valid_coords(char *crd)
{
	int	i;
	int	pts;

	if (!*crd || *crd == '.')
		return (0);
	i = 0;
	pts = 0;
	if (crd[i] == '+' || crd[i] == '-')
		i++;
	while (crd[i])
	{
		if (crd[i] != '.' && (crd[i] < '0' || crd[i] > '9'))
			return (0);
		if (crd[i] == '.')
			pts++;
		i++;
	}
	if (pts > 1 || *crd == '.')
		return (0);
	return (1);
}
