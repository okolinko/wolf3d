/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:55:00 by akolinko          #+#    #+#             */
/*   Updated: 2018/12/06 19:55:01 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		step(t_glob *my)
{
	if (my->dir_cam_x < 0)
	{
		my->step_x = -1;
		my->side_dist_x = (my->pos_x_cam - (double)my->map_x)
		* my->delta_dist_x;
	}
	else
	{
		my->step_x = 1;
		my->side_dist_x = ((double)my->map_x + 1.0 - my->pos_x_cam)
		* my->delta_dist_x;
	}
	if (my->dir_cam_y < 0)
	{
		my->step_y = -1;
		my->side_dist_y = (my->pos_y_cam - (double)my->map_y)
		* my->delta_dist_y;
	}
	else
	{
		my->step_y = 1;
		my->side_dist_y = ((double)my->map_y + 1.0 - my->pos_y_cam)
		* my->delta_dist_y;
	}
}

void			hit_num(t_glob *my)
{
	if (my->arr[my->map_x][my->map_y].z == 1)
		my->hit = 1;
	else if (my->arr[my->map_x][my->map_y].z == 2)
		my->hit = 2;
	else if (my->arr[my->map_x][my->map_y].z == 3)
		my->hit = 3;
	else if (my->arr[my->map_x][my->map_y].z == 4)
		my->hit = 4;
}

static void		hit(t_glob *my)
{
	while ((my->hit < 1 && my->map_y > 0) && my->map_y < my->x_len &&
		my->map_x > 0)
	{
		if (my->side_dist_x < my->side_dist_y)
		{
			my->side = 0;
			my->map_x += my->step_x;
			my->side_dist_x += my->delta_dist_x;
		}
		else
		{
			my->side = 1;
			my->map_y += my->step_y;
			my->side_dist_y += my->delta_dist_y;
		}
		hit_num(my);
	}
}

void			raycast(t_glob *my)
{
	step(my);
	hit(my);
	if (my->side == 0)
		my->wall_dist = fabs((my->map_x - my->pos_x_cam + (1 - my->step_x)
		/ 2) / my->dir_cam_x);
	else
		my->wall_dist = fabs((my->map_y - my->pos_y_cam + (1 - my->step_y)
		/ 2) / my->dir_cam_y);
	if (my->wall_dist <= 0.05)
		my->wall_dist = 0.05;
	my->height = fabs(WIDTH / my->wall_dist);
	if ((my->start = -(my->height) / my->dh + WIDTH / 2) < 0)
		my->start = 0;
	if ((my->end = my->height / 2 + WIDTH / 2) >= WIDTH)
		my->end = WIDTH - 1;
}
