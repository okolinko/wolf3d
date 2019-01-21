/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:51:58 by akolinko          #+#    #+#             */
/*   Updated: 2018/12/10 17:51:59 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

unsigned int	add_smog(unsigned int c, double dist)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = c;
	g = c >> 8;
	b = c >> 16;
	dist = dist / 500;
	if (dist > 0.9)
		dist = 0.9;
	r = r - (r * dist);
	g = g - (g * dist);
	b = b - (b * dist);
	return ((r << 16) + (g << 8) + b);
}

void			put_pixel(t_glob *my, int x, int y, int color)
{
	int				i;
	unsigned int	pixel;

	i = 0;
	pixel = x * (my->bits_p_p / 8) + y * (my->size_line);
	while (i < (my->bits_p_p / 8))
	{
		my->addr[pixel + i] = color;
		color >>= 8;
		i++;
	}
}
