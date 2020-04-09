/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 16:39:18 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 14:50:11 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		mouse_movement(int x, int y, struct s_param *p)
{
	int x_diff;
	int y_diff;

	x_diff = (x - (WIDTH * 0.5)) * .1;
	y_diff = (y - (HEIGHT * .5)) * .1;
	if (x_diff == 0 && (x - (WIDTH * 0.5)) > 0)
		x_diff = 1;
	if (x_diff == 0 && (x - (WIDTH * 0.5)) < 0)
		x_diff = -1;
	if (y_diff == 0 && (y - (HEIGHT * .5)) > 0)
		y_diff = 1;
	if (y_diff == 0 && (y - (HEIGHT * .5)) < 0)
		y_diff = -1;
	p->angle_test += (x_diff * 0.25);
	mlx_mouse_move(p->mlx->win_ptr, WIDTH * 0.5, HEIGHT * 0.5);
	mlx_mouse_hide();
	algo(p);
	return (0);
}

int		place_player(t_param *p)
{
	int i;
	int j;
	int count;

	j = -1;
	count = 0;
	while (++j < p->sizey && (i = -1))
		while (++i < p->sizex)
			if (p->map[j][i] == 2)
			{
				count++;
				p->me.x = i + 0.5;
				p->me.y = j + 0.5;
			}
	if (count != 1)
		return (-1);
	return (0);
}

int		get_size_map(t_param *p, t_wolf *wolf, int i, int len)
{
	while (wolf->map[++i] && !(len = 0))
	{
		wolf->j = -1;
		while (wolf->map[i][++wolf->j])
		{
			if (wolf->map[i][wolf->j] != ' ' 		\
						&& !(ft_isdigit(wolf->map[i][wolf->j])))
				return (0);
			if (ft_isdigit(wolf->map[i][wolf->j]))
			{
				while (wolf->map[i][wolf->j] 		\
						&& ft_isdigit(wolf->map[i][wolf->j]))
					wolf->j++;
				if (wolf->map[i][wolf->j] == ' ' 	\
						|| wolf->map[i][wolf->j] == '\0')
					len++;
			}
			if (wolf->map[i][wolf->j] == '\0')
				break ;
		}
	}
	p->sizey = i;
	p->sizex = len;
	return (1);
}

int		check_valid_map(t_param *p)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < p->sizex && j < p->sizey)
	{
		while (i < p->sizex)
		{
			if (p->map[0][i] != 1 || p->map[p->sizey - 1][i] != 1)
				count++;
			i++;
		}
		while (j < p->sizey)
		{
			if (p->map[j][0] != 1 || p->map[j][p->sizex - 1] != 1)
				count++;
			j++;
		}
	}
	return (count);
}

void	ft_split_tab(char *tmp, t_wolf *wolf, t_param *p)
{
	while (wolf->map[wolf->i][wolf->j] && wolf->l < p->sizex)
	{
		while (wolf->map[wolf->i][wolf->j]				\
				&& wolf->map[wolf->i][wolf->j] == ' ')
			wolf->j++;
		while (ft_isdigit(wolf->map[wolf->i][wolf->j]) 	\
				|| wolf->map[wolf->i][wolf->j] == '-')
			tmp[wolf->k++] = wolf->map[wolf->i][wolf->j++];
		wolf->k = 0;
		if (ft_atoi(tmp) < 0 || ft_atoi(tmp) > 2)
			ft_error("Bad number in map");
		p->map[wolf->i][wolf->l++] = ft_atoi(tmp);
		if (ft_atoi(tmp) == 2)
		{
			wolf->rl = wolf->l;
			wolf->im = wolf->i;
		}
		ft_bzero(tmp, 11);
	}
}
