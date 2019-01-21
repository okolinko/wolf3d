/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:21:18 by akolinko          #+#    #+#             */
/*   Updated: 2018/12/07 19:21:20 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_textures2(t_glob *my, int a, int b)
{
	a = 512;
	b = 512;
	my->tex[10].img = mlx_xpm_file_to_image(my->mlx_ptr,
			"textures/sky.xpm", &a, &b);
	my->tex[10].data = mlx_get_data_addr(my->tex[10].img, &my->tex[10].bpp,
			&my->tex[10].sizeline, &my->tex[10].endian2);
}

void	load_textures1_12(t_glob *my, int a, int b)
{
	my->tex[11].img = mlx_xpm_file_to_image(my->mlx_ptr,
			"textures/redbrick.xpm", &a, &b);
	my->tex[11].data = mlx_get_data_addr(my->tex[11].img, &my->tex[11].bpp,
			&my->tex[11].sizeline, &my->tex[11].endian2);
	my->tex[12].img = mlx_xpm_file_to_image(my->mlx_ptr,
			"textures/pic/bluebrickimage.xpm", &a, &b);
	my->tex[12].data = mlx_get_data_addr(my->tex[12].img, &my->tex[12].bpp,
			&my->tex[12].sizeline, &my->tex[12].endian2);
	my->tex[13].img = mlx_xpm_file_to_image(my->mlx_ptr,
			"textures/pic/ceiling.xpm", &a, &b);
	my->tex[13].data = mlx_get_data_addr(my->tex[13].img, &my->tex[13].bpp,
			&my->tex[13].sizeline, &my->tex[13].endian2);
	my->tex[14].img = mlx_xpm_file_to_image(my->mlx_ptr,
			"textures/mossy.xpm", &a, &b);
	my->tex[14].data = mlx_get_data_addr(my->tex[14].img, &my->tex[14].bpp,
			&my->tex[14].sizeline, &my->tex[14].endian2);
	my->tex[15].img = mlx_xpm_file_to_image(my->mlx_ptr,
			"textures/grass.xpm", &a, &b);
	my->tex[15].data = mlx_get_data_addr(my->tex[15].img, &my->tex[15].bpp,
			&my->tex[15].sizeline, &my->tex[15].endian2);
}

void	load_textures1_2(t_glob *my, int a, int b)
{
	my->tex[4].img = mlx_xpm_file_to_image(my->mlx_ptr,
			"textures/pic/brickimage3.xpm", &a, &b);
	my->tex[4].data = mlx_get_data_addr(my->tex[4].img, &my->tex[4].bpp,
			&my->tex[4].sizeline, &my->tex[4].endian2);
	my->tex[5].img = mlx_xpm_file_to_image(my->mlx_ptr,
			"textures/brick.xpm", &a, &b);
	my->tex[5].data = mlx_get_data_addr(my->tex[5].img, &my->tex[5].bpp,
			&my->tex[5].sizeline, &my->tex[5].endian2);
	my->tex[6].img = mlx_xpm_file_to_image(my->mlx_ptr,
			"textures/bookshelf.xpm", &a, &b);
	my->tex[6].data = mlx_get_data_addr(my->tex[6].img, &my->tex[6].bpp,
			&my->tex[6].sizeline, &my->tex[6].endian2);
	my->tex[7].img = mlx_xpm_file_to_image(my->mlx_ptr,
			"textures/pic/ceiling.xpm", &a, &b);
	my->tex[7].data = mlx_get_data_addr(my->tex[7].img, &my->tex[7].bpp,
			&my->tex[7].sizeline, &my->tex[7].endian2);
	my->tex[8].img = mlx_xpm_file_to_image(my->mlx_ptr,
			"textures/pic/floor.xpm", &a, &b);
	my->tex[8].data = mlx_get_data_addr(my->tex[8].img, &my->tex[8].bpp,
			&my->tex[8].sizeline, &my->tex[8].endian2);
	my->tex[9].img = mlx_xpm_file_to_image(my->mlx_ptr,
			"textures/pumpkin.xpm", &a, &b);
	my->tex[9].data = mlx_get_data_addr(my->tex[9].img, &my->tex[9].bpp,
			&my->tex[9].sizeline, &my->tex[9].endian2);
	load_textures1_12(my, a, b);
}

void	load_texture(t_glob *my)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	my->tex[0].img = mlx_xpm_file_to_image(my->mlx_ptr,
			"textures/wood.xpm", &a, &b);
	my->tex[0].data = mlx_get_data_addr(my->tex[0].img, &my->tex[0].bpp,
			&my->tex[0].sizeline, &my->tex[0].endian2);
	my->tex[1].img = mlx_xpm_file_to_image(my->mlx_ptr,
			"textures/pic/brickimage2.xpm", &a, &b);
	my->tex[1].data = mlx_get_data_addr(my->tex[1].img, &my->tex[1].bpp,
			&my->tex[1].sizeline, &my->tex[1].endian2);
	my->tex[2].img = mlx_xpm_file_to_image(my->mlx_ptr,
			"textures/wall.xpm", &a, &b);
	my->tex[2].data = mlx_get_data_addr(my->tex[2].img, &my->tex[2].bpp,
			&my->tex[2].sizeline, &my->tex[2].endian2);
	my->tex[3].img = mlx_xpm_file_to_image(my->mlx_ptr,
			"textures/crafting.xpm", &a, &b);
	my->tex[3].data = mlx_get_data_addr(my->tex[3].img, &my->tex[3].bpp,
			&my->tex[3].sizeline, &my->tex[3].endian2);
	load_textures1_2(my, a, b);
	load_textures2(my, a, b);
}
