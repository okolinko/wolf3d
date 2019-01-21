/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:07:21 by akolinko          #+#    #+#             */
/*   Updated: 2018/12/10 18:07:32 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					exit_x(void *par)
{
	par = NULL;
	exit(1);
}

static int			rotate(int keycode, double tmp_dir,
		double tmp_plane, t_glob *my)
{
	if (keycode == 123)
	{
		my->dir_x = my->dir_x * cos(my->rtspd)
					- my->dir_y * sin(my->rtspd);
		my->dir_y = tmp_dir * sin(my->rtspd)
				+ my->dir_y * cos(my->rtspd);
		my->plane_x = my->plane_x * cos(my->rtspd)
					- my->plane_y * sin(my->rtspd);
		my->plane_y = tmp_plane * sin(my->rtspd)
				+ my->plane_y * cos(my->rtspd);
	}
	if (keycode == 124)
	{
		my->dir_x = my->dir_x * cos(-my->rtspd)
					- my->dir_y * sin(-my->rtspd);
		my->dir_y = tmp_dir * sin(-my->rtspd)
					+ my->dir_y * cos(-my->rtspd);
		my->plane_x = my->plane_x * cos(-my->rtspd)
					- my->plane_y * sin(-my->rtspd);
		my->plane_y = tmp_plane * sin(-my->rtspd)
					+ my->plane_y * cos(-my->rtspd);
	}
	return (0);
}

static int			step_left_right(int keycode, t_glob *my)
{
	if (keycode == 2)
	{
		if (my->arr[(int)(my->pos_x + my->plane_x * my->mvspd)]
			[(int)(my->pos_y)].z == 0 || my->arr[(int)(my->pos_x +
			my->plane_x * my->mvspd)][(int)(my->pos_y)].z == 0)
			my->pos_x += my->plane_x * my->mvspd;
		if (my->arr[(int)(my->pos_x)][(int)(my->pos_y + my->plane_y
		* my->mvspd)].z == 0 || my->arr[(int)(my->pos_x)]
		[(int)(my->pos_y + my->plane_y * my->mvspd)].z == 0)
			my->pos_y += my->plane_y * my->mvspd;
	}
	if (keycode == 0)
	{
		if (my->arr[(int)(my->pos_x - my->plane_x * my->mvspd)]
		[(int)(my->pos_y)].z == 0 || my->arr[(int)(my->pos_x -
		my->plane_x * my->mvspd)][(int)(my->pos_y)].z == 0)
			my->pos_x -= my->plane_x * my->mvspd;
		if (my->arr[(int)(my->pos_x)][(int)(my->pos_y - my->plane_y
		* my->mvspd)].z == 0 || my->arr[(int)(my->pos_x)]
		[(int)(my->pos_y - my->plane_y * my->mvspd)].z == 0)
			my->pos_y -= my->plane_y * my->mvspd;
	}
	return (0);
}

static int			sprinter(int key, t_glob *my)
{
	step_left_right(key, my);
	if (key == 257)
	{
		if (my->sprint == 0)
		{
			my->mvspd = 0.4;
			my->sprint = 1;
		}
		else
		{
			my->mvspd = 0.1;
			my->sprint = 0;
		}
	}
	quiet_step(my, key);
	return (0);
}

int					deal_key(int key, t_glob *my)
{
	if (key == 53)
	{
		mlx_destroy_window(my->mlx_ptr, my->win_ptr);
		exit(1);
	}
	key_up(my, key);
	if (key == 15)
		values_wolf(my);
	rotate(key, my->dir_x, my->plane_x, my);
	sprinter(key, my);
	wolf_raycaster(my);
	return (0);
}
