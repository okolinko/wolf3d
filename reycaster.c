/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:49:28 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/29 11:49:29 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			draw_wall(t_glob *t)
{
	if (t->side == 0)
		t->x_wall = t->pos_y + t->wall_dist * t->dir_cam_y;
	else
		t->x_wall = t->pos_x + t->wall_dist * t->dir_cam_x;
	t->text_x = (int)(t->x_wall * (double)(64));
	if (t->side == 0 && t->dir_cam_x > 0)
		t->text_x = 64 - t->text_x - 1;
	if (t->side == 1 && t->dir_cam_y < 0)
		t->text_x = 64 - t->text_x - 1;
	t->text_x = abs(t->text_x);
}

void			draw_wall_start(t_glob *my, int y)
{
	my->text_y = abs((((y * 256 - WIDTH * 128 + my->height
			* 128) * 64) / my->height) / 256);
	draw_wall(my);
	my_color(my, y);
}

static void		floor_and_ceiling(t_glob *my, int y)
{
	int		color;

	color = 0;
	while (y < WIDTH)
	{
		if (y < my->start + my->player_z)
		{
			ft_memcpy(my->addr + 4 * HEIGHT * y + my->i * 4,
					&my->tex[10].data[y % 512 *
			my->tex[10].sizeline + my->i % 512 * my->tex[10].bpp
			/ 8], sizeof(int));
		}
		else if (y > my->end + my->player_z)
		{
			color = add_smog(0x330066, WIDTH - y);
			put_pixel(my, my->i, y, color);
		}
		else
		{
			if (my->hit > 0)
				draw_wall_start(my, y);
		}
		y++;
	}
}

int				wolf_raycaster(t_glob *my)
{
	int y;

	y = 0;
	my->i = 0;
	while (my->i++ < HEIGHT)
	{
		my->camera_x = 2 * my->i / (double)HEIGHT - 1;
		my->side = 0;
		my->hit = 0;
		my->pos_x_cam = my->pos_x;
		my->pos_y_cam = my->pos_y;
		my->dir_cam_x = my->dir_x + my->plane_x * my->camera_x;
		my->dir_cam_y = my->dir_y + my->plane_y * my->camera_x;
		my->map_x = (int)my->pos_x_cam;
		my->map_y = (int)my->pos_y_cam;
		my->delta_dist_x = sqrt(1 + pow(my->dir_cam_y / my->dir_cam_x, 2));
		my->delta_dist_y = sqrt(1 + pow(my->dir_cam_x / my->dir_cam_y, 2));
		raycast(my);
		floor_and_ceiling(my, y);
	}
	radar(my);
	mlx_put_image_to_window(my->mlx_ptr, my->win_ptr, my->image, 0, 0);
	fps(my);
	ft_string_put(my);
	return (0);
}
