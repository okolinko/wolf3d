/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:25:44 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/24 10:25:45 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		valid_map(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if ((str[i] >= '0' && str[i] <= '4') || str[i] == ' ' ||
			str[i] == '\n' || str[i] == '\0')
			i++;
		else
			error1();
		i++;
	}
}

int			ft_long_map(char *argv, t_glob *my)
{
	int			fd;
	char		*line;
	char		**tab;
	int			len;
	int			y;

	len = 0;
	y = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)
		error1();
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			tab = ft_strsplit(line, ' ');
			free(line);
			len = ft_len_x(tab);
			ft_free_matrix(&tab);
			y++;
		}
		if (len <= 0)
			error1();
		my->y_len = y;
	}
	return (len);
}

void		ft_free_matrix(char ***str)
{
	int i;

	i = -1;
	while ((*str)[++i])
	{
		free((*str)[i]);
		(*str)[i] = NULL;
	}
	free(*str);
	*str = NULL;
}

int			ft_len_x(char **str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

int			ft_check(t_glob *my, char *argv)
{
	int		fd;
	char	*line;
	char	**tab;
	int		check_line;

	check_line = 0;
	if ((fd = open(argv, O_RDONLY)) > 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			tab = ft_strsplit(line, ' ');
			check_line = ft_len_x(tab);
			if (my->x_len > check_line || my->x_len < check_line)
				error1();
			valid_map(line);
			free(line);
			ft_free_matrix(&tab);
		}
	}
	return (1);
}
