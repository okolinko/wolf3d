/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:00:01 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/24 10:00:09 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_map_creat(t_cord **map_save, t_map *read, t_glob *my)
{
	int		x_ln;
	int		y_up;

	y_up = 0;
	while (my->y_len > y_up)
	{
		x_ln = 0;
		while (my->x_len > x_ln)
		{
			map_save[y_up][x_ln].z = ft_atoi(read->str[x_ln]);
			if (map_save[y_up][x_ln].z < 0 || map_save[y_up][x_ln].z > 4)
				error1();
			x_ln++;
		}
		y_up++;
		read = read->next;
	}
}

t_cord			**ft_save_matrix(t_map *read, t_glob *my)
{
	int			i;
	t_cord		**map_save;

	if (!(map_save = (t_cord **)malloc(my->y_len * sizeof(t_cord *))))
		return (0);
	i = 0;
	while (i < my->y_len)
	{
		if (!(map_save[i] = (t_cord *)malloc(my->x_len * sizeof(t_cord))))
			return (0);
		i++;
	}
	ft_map_creat(map_save, read, my);
	return (map_save);
}

void			ft_save_list(t_map **save, char **line)
{
	t_map		*temp;
	t_map		*tmp2;

	temp = (t_map *)malloc(sizeof(t_map));
	temp->str = line;
	temp->next = NULL;
	if (*save == NULL)
		*save = temp;
	else
	{
		tmp2 = *save;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = temp;
	}
}

t_map			*ft_read(char *test_file)
{
	int			fd;
	t_map		*save;
	char		*line;
	char		**tab;

	save = NULL;
	if ((fd = open(test_file, O_RDONLY)) > 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			tab = ft_strsplit(line, ' ');
			free(line);
			ft_save_list(&save, tab);
		}
	}
	return (save);
}
