/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:20:55 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/24 10:20:56 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		error(void)
{
	ft_putendl("usage: wrong amount arguments");
	exit(1);
}

void		error1(void)
{
	ft_putendl("error: invalid map!");
	ft_putendl("Example map ->>> test.map");
	ft_putendl("1 1 1 1 1");
	ft_putendl("1 4 0 0 1");
	ft_putendl("1 0 0 2 1");
	ft_putendl("1 4 0 3 1");
	ft_putendl("1 1 1 1 1");
	exit(2);
}
