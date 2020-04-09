/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 23:41:47 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 14:49:31 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	slide(t_param *p, t_real *move)
{
	if (p->map[(int)(p->me.y)][(int)(p->me.x + move->x)] != 1 			\
			&& p->map[(int)(p->me.y + move->y)][(int)(p->me.x)] != 1 	\
			&& p->map[(int)(p->me.y + move->y)][(int)(p->me.x + move->x)] != 1)
	{
		if (p->map[(int)(p->me.y)][(int)(p->me.x + move->x * 2)] == 1)
			p->me.y += move->y;
		else if (p->map[(int)(p->me.y + move->y * 2)][(int)(p->me.x)] == 1)
			p->me.x += move->x;
		else
		{
			p->me.x += move->x;
			p->me.y += move->y;
		}
	}
	else if (p->map[(int)(p->me.y)][(int)(p->me.x + move->x)] == 1 		\
			&& p->map[(int)(p->me.y + move->y)][(int)(p->me.x)] != 1)
		p->me.y += move->y;
	else if (p->map[(int)(p->me.y)][(int)(p->me.x + move->x)] != 1 		\
			&& p->map[(int)(p->me.y + move->y)][(int)(p->me.x)] == 1)
		p->me.x += move->x;
	if (p->me.x == 4)
		p->me.x += 0.00001;
}

static int	key_release(int key, t_param *p)
{
	if (key >= MAX)
		return (0);
	p->keys[key] = 0;
	return (0);
}

static int	ft_deal_key(int key, t_param *p)
{
	t_real		move;

	if (key >= MAX)
		return (0);
	p->keys[key] = 1;
	move = (t_real){0, 0};
	if (p->keys[ESC])
		exit(0);
	if (p->keys[DOWN] || p->keys[S])
		move.y += 0.1;
	if (p->keys[UP] || p->keys[W])
		move.y -= 0.1;
	if (p->keys[LEFT] || p->keys[A])
		move.x -= 0.1;
	if (p->keys[RIGHT] || p->keys[D])
		move.x += 0.1;
	if (p->keys[LESS])
		p->angle_test -= 5;
	if (p->keys[MORE])
		p->angle_test += 5;
	move = real_turn(move, p->angle_test);
	slide(p, &move);
	algo(p);
	return (0);
}

static void	init(int ac, char **av, t_param *p)
{
	int		fd;
	int		buf[BUFF_SIZE + 1];
	t_wolf	*wolf;

	if (ac != 2)
		ft_error("Wrong numbers of arguments");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error("Invalid file");
	if (fd < 0 || BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
		ft_error("Invalid file");
	if (!(p->mlx = malloc(sizeof(t_mlx))))
		ft_error("P->mlx Malloc error");
	if (!(wolf = malloc(sizeof(t_wolf))))
		ft_error("Wolf Malloc error");
	wolf->map = create_char_map(wolf, &fd);
	if (get_size_map(p, wolf, -1, 0) == 0)
		ft_error("Bad size map");
	p->map = get_int_map(p, wolf, -1);
	if ((check_valid_map(p)) != 0)
		ft_error("Invalid map");
	if (p->me.y <= 0 || p->me.y >= p->sizey 	\
			|| p->me.x <= 0 || p->me.x >= p->sizex)
		ft_error("Invalid position");
	p->mlx->mlx_ptr = mlx_init();
	p->mlx->win_ptr = mlx_new_window(p->mlx->mlx_ptr, WIDTH, HEIGHT, "Wolf3D");
}

int			main(int ac, char **av)
{
	t_param	*p;
	int		i;

	if (!(p = malloc(sizeof(t_param))))
		ft_error("P Malloc error");
	init(ac, av, p);
	i = -1;
	while (++i < MAX)
		p->keys[i] = 0;
	xpm_to_img(p->mlx->mlx_ptr, &p->mlx->texture_n, "textures/blue_brick.xpm");
	xpm_to_img(p->mlx->mlx_ptr, &p->mlx->texture_s, "textures/grey_brick.xpm");
	xpm_to_img(p->mlx->mlx_ptr, &p->mlx->texture_e, "textures/brown_brick.xpm");
	xpm_to_img(p->mlx->mlx_ptr, &p->mlx->texture_o, "textures/rock.xpm");
	ft_create_img(p->mlx->mlx_ptr, &p->mlx->win, WIDTH, HEIGHT);
	p->angle_test = 0;
	p->vec = real_turn((t_real){0, -1}, p->angle_test);
	mlx_mouse_hide();
	algo(p);
	mlx_hook(p->mlx->win_ptr, 3, 0, &key_release, p);
	mlx_hook(p->mlx->win_ptr, 2, 0, &ft_deal_key, p);
	mlx_hook(p->mlx->win_ptr, 17, 0, &ft_exit, p);
	mlx_hook(p->mlx->win_ptr, 6, 0, &mouse_movement, p);
	mlx_loop(p->mlx->mlx_ptr);
	return (0);
}
