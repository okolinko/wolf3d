/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:54:25 by akolinko          #+#    #+#             */
/*   Updated: 2018/12/10 17:54:26 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			key_up(t_glob *my, int key)
{
	if (key == 126 || key == 13)
	{
		if (my->arr[(int)(my->pos_x + my->dir_x * my->mvspd)]
			[(int)(my->pos_y)].z == 0)
			my->pos_x += my->dir_x * my->mvspd;
		if (my->arr[(int)(my->pos_x)][(int)(my->pos_y + my->dir_y
														* my->mvspd)].z == 0)
			my->pos_y += my->dir_y * my->mvspd;
	}
	if (key == 125 || key == 1)
	{
		if (my->arr[(int)(my->pos_x - my->dir_x * my->mvspd)]
			[(int)(my->pos_y)].z == 0)
			my->pos_x -= my->dir_x * my->mvspd;
		if (my->arr[(int)(my->pos_x)][(int)(my->pos_y - my->dir_y
														* my->mvspd)].z == 0)
			my->pos_y -= my->dir_y * my->mvspd;
	}
}

void			quiet_step(t_glob *my, int key)
{
	if (key == 256)
	{
		if (my->sprint == 0)
		{
			my->mvspd = 0.04;
			my->sprint = 1;
		}
		else
		{
			my->mvspd = 0.1;
			my->sprint = 0;
		}
	}
}
