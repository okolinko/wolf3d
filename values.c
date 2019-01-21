/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:37:37 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/29 10:37:38 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	values_wolf(t_glob *my)
{
	my->plane_x = 0.0;
	my->plane_y = 0.66;
	my->dh = 2.0;
	my->sprint = 0;
	my->dir_x = -1;
	my->dir_y = 0;
	my->mvspd = 0.1;
	my->rtspd = 0.05;
	my->sprint = 0;
	my->text_x = 0;
	my->text_y = 0;
	my->player_z = 0;
	my->pos_x = my->tmp_pos_x;
	my->pos_y = my->tmp_pos_y;
	load_texture(my);
}
