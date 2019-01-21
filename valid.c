/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:40:45 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/24 11:40:46 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			check_nul(t_glob *my)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < my->y_len)
	{
		j = 0;
		while (j < my->x_len)
		{
			if (my->arr[i][j].z == 0)
			{
				my->pos_y = j + 0.5;
				my->pos_x = i + 0.5;
				my->tmp_pos_x = my->pos_x;
				my->tmp_pos_y = my->pos_y;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int			check_side(t_glob *my)
{
	int		i;

	i = 0;
	while (i < my->x_len)
	{
		if (my->arr[0][i].z == 0)
			return (0);
		if (my->arr[my->y_len - 1][i].z == 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < my->y_len)
	{
		if (my->arr[i][0].z == 0)
			return (0);
		if (my->arr[i][my->x_len - 1].z == 0)
			return (0);
		i++;
	}
	return (1);
}

int			parser(t_glob *my)
{
	if (check_side(my) == 0)
		error1();
	else if (check_nul(my) == 0)
		error1();
	return (1);
}
