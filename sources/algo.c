/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 17:28:32 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 15:16:42 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static t_mlx_img	choice_tex(char side, t_param *p)
{
	if (side == 'n')
		return (p->mlx->texture_n);
	if (side == 's')
		return (p->mlx->texture_s);
	if (side == 'e')
		return (p->mlx->texture_e);
	return (p->mlx->texture_o);
}

static void			display_walls(t_mlx_img img, t_mlx_img tex, 	\
		int size, t_real x_tmp)
{
	t_rgb	color;
	float	tmp;
	float	y;

	tmp = 0.5 * (HEIGHT - size) < 0 ? -0.5 * (HEIGHT - size) : 0;
	if ((y = 0.5 * (HEIGHT - size)) < 0)
		y = 0;
	while (y < 0.5 * (HEIGHT + size) && y < HEIGHT)
	{
		if ((color = ft_get_pixel(tex, x_tmp.y * tex.width, 		\
				(tmp++) * tex.height / size)).a)
			color = y < HEIGHT * 0.5 ? (t_rgb){200, 200, 255, 0} 	\
					: (t_rgb){100, 50, 0, 0};
		ft_pixel_put_rgb(img, x_tmp.x, y++, color);
	}
}

void				display(t_param *p, float dist, int x, char side)
{
	int			y;
	float		size;
	float		tmp_tex;

	tmp_tex = side == 'n' || side == 's' ? p->tmp_tex_y : p->tmp_tex_x;
	dist *= cos(ft_deg_to_rad((x - WIDTH * 0.5) * FOV / WIDTH));
	size = HEIGHT / dist;
	if (!dist || !size)
		return ;
	y = 0;
	while (y <= 0.5 * (HEIGHT - size))
		ft_pixel_put_rgb(p->mlx->win, x, y++, (t_rgb){200, 200, 255, 0});
	display_walls(p->mlx->win, choice_tex(side, p), size, 	\
			(t_real){x, (tmp_tex - (int)tmp_tex)});
	y = 0.5 * (HEIGHT + size);
	while (y < HEIGHT)
		ft_pixel_put_rgb(p->mlx->win, x, y++, (t_rgb){100, 50, 0, 0});
}

static void			choice_check(t_param *p)
{
	int	i;

	i = -1;
	while (++i < WIDTH)
		if (!p->rays[i].d.x && !p->rays[i].d.y)
			ft_error("Ray null");
		else if (!p->rays[i].d.x && p->rays[i].d.y < 0)
			check_n_s_e_o(p, i, 'n');
		else if (!p->rays[i].d.x && p->rays[i].d.y > 0)
			check_n_s_e_o(p, i, 's');
		else if (p->rays[i].d.x < 0 && !p->rays[i].d.y)
			check_n_s_e_o(p, i, 'e');
		else if (p->rays[i].d.x > 0 && !p->rays[i].d.y)
			check_n_s_e_o(p, i, 'o');
		else if (p->rays[i].d.x < 0 && p->rays[i].d.y < 0)
			check_no(p, i);
		else if (p->rays[i].d.x > 0 && p->rays[i].d.y < 0)
			check_ne(p, i);
		else if (p->rays[i].d.x < 0 && p->rays[i].d.y > 0)
			check_so(p, i);
		else if (p->rays[i].d.x > 0 && p->rays[i].d.y > 0)
			check_se(p, i);
}

void				algo(t_param *p)
{
	int	i;

	mlx_mouse_hide();
	if (!(p->rays = malloc(sizeof(t_2d_ray) * WIDTH)))
		ft_error("Malloc error");
	i = -1;
	while (++i < WIDTH)
		p->rays[i] = create_2d_ray(p->me, 								\
				op_real(real_turn((t_real)								\
				{ft_deg_to_rad((i - WIDTH * 0.5) * FOV / WIDTH), -1}, 	\
				p->angle_test), '+', p->me));
	p->vec = real_turn((t_real){0, -1}, p->angle_test);
	choice_check(p);
	free(p->rays);
	mlx_put_image_to_window(p->mlx->mlx_ptr, 							\
			p->mlx->win_ptr, p->mlx->win.ptr, 0, 0);
	ft_img_dark(p->mlx->win);
}
