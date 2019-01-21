/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:16:08 by akolinko          #+#    #+#             */
/*   Updated: 2018/12/18 14:16:10 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	fps(t_glob *my)
{
	static int		my_time;
	static int		fps;
	static int		my_fps;
	char			*s;

	if (time(NULL) != my_time)
	{
		my_fps = fps;
		fps = 0;
		my_time = (int)time(NULL);
	}
	else
		fps++;
	s = ft_itoa(my_fps);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 940, 20, 0xff00, "FPS :");
	mlx_string_put(my->mlx_ptr, my->win_ptr, 1000, 20, 0xff00, s);
	free(s);
}
