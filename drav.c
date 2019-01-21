/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drav.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:41:18 by akolinko          #+#    #+#             */
/*   Updated: 2018/12/10 16:41:19 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			my_color2(t_glob *my, int y)
{
	if (my->hit == 3)
	{
		if (my->side == 0 && my->dir_cam_x >= 0)
			ft_memcpy(my->addr + 4 * HEIGHT * y + my->i * 4,
					&my->tex[11].data[my->text_y % 64 * my->tex[11].sizeline +
					my->text_x % 64 * my->tex[11].bpp / 8], sizeof(int));
		else if (my->side == 0 && my->dir_cam_x < 0)
			ft_memcpy(my->addr + 4 * HEIGHT * y + my->i * 4,
					&my->tex[12].data[my->text_y % 64 * my->tex[12].sizeline +
					my->text_x % 64 * my->tex[12].bpp / 8], sizeof(int));
		else if ((my->side == 1) && (my->dir_cam_y >= 0))
			ft_memcpy(my->addr + 4 * HEIGHT * y + my->i * 4,
					&my->tex[9].data[my->text_y % 64 * my->tex[9].sizeline +
					my->text_x % 64 * my->tex[9].bpp / 8], sizeof(int));
		else
			ft_memcpy(my->addr + 4 * HEIGHT * y + my->i * 4,
					&my->tex[14].data[my->text_y % 64 * my->tex[14].sizeline +
					my->text_x % 64 * my->tex[14].bpp / 8], sizeof(int));
	}
}

void			my_color3(t_glob *my, int y)
{
	if (my->hit == 4)
	{
		if (my->side == 0 && my->dir_cam_x >= 0)
			ft_memcpy(my->addr + 4 * HEIGHT * y + my->i * 4,
					&my->tex[1].data[my->text_y % 64 * my->tex[1].sizeline +
					my->text_x % 64 * my->tex[1].bpp / 8], sizeof(int));
		else if (my->side == 0 && my->dir_cam_x < 0)
			ft_memcpy(my->addr + 4 * HEIGHT * y + my->i * 4,
					&my->tex[2].data[my->text_y % 64 * my->tex[2].sizeline +
					my->text_x % 64 * my->tex[2].bpp / 8], sizeof(int));
		else if ((my->side == 1) && (my->dir_cam_y >= 0))
			ft_memcpy(my->addr + 4 * HEIGHT * y + my->i * 4,
					&my->tex[3].data[my->text_y % 64 * my->tex[3].sizeline +
					my->text_x % 64 * my->tex[3].bpp / 8], sizeof(int));
		else
			ft_memcpy(my->addr + 4 * HEIGHT * y + my->i * 4,
					&my->tex[7].data[my->text_y % 64 * my->tex[7].sizeline +
					my->text_x % 64 * my->tex[7].bpp / 8], sizeof(int));
	}
}

void			my_color5(t_glob *my, int y)
{
	if (my->hit == 1)
	{
		ft_memcpy(my->addr + 4 * HEIGHT * y + my->i * 4,
				&my->tex[5].data[my->text_y % 64 * my->tex[5].sizeline +
				my->text_x % 64 * my->tex[5].bpp / 8], sizeof(int));
	}
}

void			my_color(t_glob *my, int y)
{
	my_color5(my, y);
	if (my->hit == 2)
	{
		if (my->side == 0 && my->dir_cam_x >= 0)
			ft_memcpy(my->addr + 4 * HEIGHT * y + my->i * 4,
					&my->tex[4].data[my->text_y % 64 * my->tex[4].sizeline +
					my->text_x % 64 * my->tex[4].bpp / 8], sizeof(int));
		else if (my->side == 0 && my->dir_cam_x < 0)
			ft_memcpy(my->addr + 4 * HEIGHT * y + my->i * 4,
					&my->tex[0].data[my->text_y % 64 * my->tex[0].sizeline +
					my->text_x % 64 * my->tex[0].bpp / 8], sizeof(int));
		else if (my->side == 1 && my->dir_cam_y >= 0)
			ft_memcpy(my->addr + 4 * HEIGHT * y + my->i * 4,
					&my->tex[6].data[my->text_y % 64 * my->tex[6].sizeline +
					my->text_x % 64 * my->tex[6].bpp / 8], sizeof(int));
		else
			ft_memcpy(my->addr + 4 * HEIGHT * y + my->i * 4,
					&my->tex[8].data[my->text_y % 64 * my->tex[8].sizeline +
					my->text_x % 64 * my->tex[8].bpp / 8], sizeof(int));
	}
	my_color2(my, y);
	my_color3(my, y);
}
