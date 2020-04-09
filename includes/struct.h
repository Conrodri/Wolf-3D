/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/10 01:19:53 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 12:28:19 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_wolf
{
	char	*line;
	char	**map;
	int		size_max;
	double	rl;
	double	im;
	int		l;
	int		i;
	int		j;
	int		k;
}				t_wolf;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_img	texture_n;
	t_mlx_img	texture_s;
	t_mlx_img	texture_e;
	t_mlx_img	texture_o;
	t_mlx_img	win;
}				t_mlx;

typedef struct	s_param
{
	t_mlx		*mlx;
	t_real		me;
	int			sizex;
	int			sizey;
	int			angle_test;
	t_real		vec;
	int			**map;
	t_2d_ray	*rays;
	t_2d_seg	arround[4];
	float		init_x;
	float		init_y;
	float		dx;
	float		dy;
	int			tabx;
	int			taby;
	int			stop_x;
	int			stop_y;
	float		dist_x;
	float		dist_y;
	float		tmp_tex_x;
	float		tmp_tex_y;
	int			keys[MAX];
}				t_param;

#endif
