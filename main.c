/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:00:01 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/24 10:00:09 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_glob		my;
	t_map		*read;

	if (argc != 2)
		error();
	my.x_len = ft_long_map(argv[1], &my);
	ft_check(&my, argv[1]);
	if (!(read = (ft_read(argv[1]))))
		return (0);
	my.arr = ft_save_matrix(read, &my);
	if (parser(&my) == 1)
		new_window(&my);
	return (0);
}
