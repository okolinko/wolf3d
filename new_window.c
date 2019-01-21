/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:43:40 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/26 11:43:41 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_string_put(t_glob *my)
{
	mlx_string_put(my->mlx_ptr, my->win_ptr, 25, 500, 0x8ff, (char*)Q);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 25, 520, 0x8ff, (char*)S);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 25, 540, 0x8ff, (char*)Z);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 25, 560, 0x8ff, (char*)W);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 25, 580, 0x8ff, (char*)E);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 25, 600, 0x8ff, (char*)R);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 25, 620, 0x8ff, (char*)T);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 25, 640, 0x8ff, (char*)U);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 25, 660, 0x8ff, (char*)I);
}

void		new_window(t_glob *my)
{
	my->mlx_ptr = mlx_init();
	my->image = mlx_new_image(my->mlx_ptr, HEIGHT, WIDTH);
	my->win_ptr = mlx_new_window(my->mlx_ptr, HEIGHT, WIDTH, F);
	my->addr = mlx_get_data_addr(my->image, &my->bits_p_p, &my->size_line,
			&my->endian);
	values_wolf(my);
	wolf_raycaster(my);
//	mlx_loop_hook(my->mlx_ptr, wolf_raycaster, my);
	mlx_hook(my->win_ptr, 2, 5, deal_key, my);
	mlx_key_hook(my->win_ptr, deal_key, my);
	mlx_hook(my->win_ptr, 17, 1L << 0, exit_x, my);
	mlx_loop(my->mlx_ptr);
}
