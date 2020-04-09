/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_sw.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 16:51:29 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 12:35:27 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	init_check_no(t_param *p, int i)
{
	p->dx = p->rays[i].a;
	p->dx = sqrt(p->dx * p->dx + 1);
	p->dy = 1 / p->rays[i].a;
	p->dy = sqrt(p->dy * p->dy + 1);
	p->init_x = p->me.x == (int)p->me.x ? 0 : p->me.x - (int)p->me.x;
	p->init_x = p->dx * p->init_x;
	p->init_y = p->me.y == (int)p->me.y ? 0 : p->me.y - (int)p->me.y;
	p->init_y = p->dy * p->init_y;
	p->stop_x = 0;
	p->stop_y = 0;
	p->dist_x = p->init_x;
	p->dist_y = p->init_y;
	p->taby = (int)p->me.y;
	p->tabx = (int)p->me.x;
	while (!p->stop_x && p->tabx--)
		if (p->rays[i].a * (p->tabx + 1) + p->rays[i].c < 0)
			p->stop_x = 2;
		else if (p->map[(int)(p->rays[i].a * (p->tabx + 1)	\
				+ p->rays[i].c)][p->tabx] == 1)
			p->stop_x = 1;
		else
			p->dist_x += p->dx;
}

void		check_no(t_param *p, int i)
{
	init_check_no(p, i);
	p->tmp_tex_x = p->rays[i].a * (p->tabx + 1) + p->rays[i].c;
	while (!p->stop_y && p->taby--)
		if ((p->taby + 1 - p->rays[i].c) / p->rays[i].a < 0)
			p->stop_y = 2;
		else if (p->map[p->taby]					\
				[(int)((p->taby + 1 - p->rays[i].c) / p->rays[i].a)] == 1)
			p->stop_y = 1;
		else
			p->dist_y += p->dy;
	p->tmp_tex_y = (p->taby + 1 - p->rays[i].c) / p->rays[i].a;
	if (p->stop_x != 1 && p->stop_y != 1)
		return ;
	if (p->stop_x == 1 && p->stop_y == 1)
		p->dist_x <= p->dist_y 						\
				? display(p, p->dist_x, i, 'o') 	\
				: display(p, p->dist_y, i, 'n');
	else
		p->stop_x == 1 								\
				? display(p, p->dist_x, i, 'o') 	\
				: display(p, p->dist_y, i, 'n');
}
