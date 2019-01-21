/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:59:37 by akolinko          #+#    #+#             */
/*   Updated: 2018/12/07 14:59:38 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		mlx_put_pixel_image_square(t_glob *my, int x, int y, int color)
{
	int	i;
	int	j;
	int f;

	i = 0;
	f = 15;
	if (my->x_len > 30 || my->y_len > 20)
		f = 5;
	if (my->x_len > 100 || my->y_len > 60)
		f = 0;
	while (i++ <= f)
	{
		j = 0;
		while (j++ <= f)
			put_pixel(my, x + i, y + j, color);
	}
}

void			radar(t_glob *my)
{
	int x;
	int y;
	int f;

	x = 0;
	f = 15;
	while (x < my->x_len)
	{
		y = 0;
		while (y < my->y_len)
		{
			if (my->x_len > 30 || my->y_len > 20)
				f = 5;
			if (my->x_len > 100 || my->y_len > 60)
				f = 0;
			if (my->arr[y][x].z > 0)
				mlx_put_pixel_image_square(my, x * f, y * f, 0x330066);
			else
				mlx_put_pixel_image_square(my, x * f, y * f, 0xffffcc);
			if (((int)my->pos_x == y && (int)my->pos_y == x))
				mlx_put_pixel_image_square(my, x * f, y * f, 0xff0000);
			y++;
		}
		x++;
	}
}
