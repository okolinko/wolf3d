/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 09:59:15 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/24 09:59:16 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define HEIGHT 1040
# define WIDTH 700
# define F "Wolf3D"
# define Q "Step straight  -  W end ^"
# define W "Step back      -  S and |"
# define E "Turn right     -   ->"
# define R "Turn left      -   <-"
# define T "Restart        -    R"
# define U "Step right     -    D"
# define I "Step left      -    A"
# define Z "Run            - Left shift"
# define S "Quiet step     - Left ctrl"

# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <time.h>

typedef struct		s_map
{
	char			**str;
	struct s_map	*next;
}					t_map;

typedef struct		s_cord
{
	int				z;
}					t_cord;

typedef struct		s_tex
{
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian2;
}					t_tex;

typedef struct		s_glob
{
	t_tex			tex[17];
	int				x_len;
	int				y_len;
	int				sprint;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			mvspd;
	double			rtspd;
	double			camera_x;
	double			pos_x_cam;
	double			pos_y_cam;
	double			dir_cam_x;
	double			dir_cam_y;
	double			plane_x;
	double			plane_y;
	double			wall_dist;
	int				i;
	int				map_x;
	int				map_y;
	int				start;
	int				end;
	int				height;
	int				side;
	int				hit;
	int				step_x;
	int				step_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				bits_p_p;
	int				size_line;
	int				endian;
	char			*addr;
	char			**map;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image;
	double			dh;
	int				len;
	int				text_x;
	int				text_y;
	double			x_wall;
	double			player_z;
	double			tmp_pos_x;
	double			tmp_pos_y;
	t_cord			**arr;
}					t_glob;

void				error(void);
void				error1(void);
int					ft_check(t_glob *my, char *str);
int					ft_len_x(char **str);
void				ft_free_matrix(char ***str);
int					ft_long_map(char *argv, t_glob *my);
void				valid_map(char *str);
int					parser(t_glob *my);
void				ft_map_creat(t_cord **map_save, t_map *read, t_glob *my);
t_cord				**ft_save_matrix(t_map *read, t_glob *my);
void				ft_save_list(t_map **save, char **line);
t_map				*ft_read(char *test_file);
void				new_window(t_glob *my);
int					exit_x(void *par);
int					deal_key(int key, t_glob *my);
void				values_wolf(t_glob *my);
int					check_side(t_glob *my);
int					wolf_raycaster(t_glob *my);
void				put_pixel(t_glob *my, int x, int y, int color);
void				raycast(t_glob *my);
void				radar(t_glob *my);
void				load_texture(t_glob *my);
void				load_textures1_2(t_glob *my, int a, int b);
void				my_color(t_glob *my, int y);
void				put_pixel(t_glob *my, int x, int y, int color);
unsigned int		add_smog(unsigned int c, double dist);
void				key_up(t_glob *my, int key);
void				ft_string_put(t_glob *my);
void				quiet_step(t_glob *my, int key);
void				fps(t_glob *my);

#endif
