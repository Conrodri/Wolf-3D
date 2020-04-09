/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_n_s_e_o.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 15:12:40 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 15:14:51 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	check_n_s_e_o(t_param *p, int i, char s)
{
	int	tabx;
	int	taby;
	int	stop;

	stop = 0;
	tabx = (int)p->me.x;
	taby = (int)p->me.y;
	while (!stop 								\
			&& ((s == 'n' && taby--) 			\
			|| (s == 's' && ++taby < p->sizey) 	\
			|| (s == 'e' && ++tabx < p->sizex) 	\
			|| (s == 'o' && tabx--)))
		if (p->map[taby][tabx] == 1)
			stop = 1;
	if (!stop)
		return ;
	if (s == 'n' || s == 'o')
		display(p, (s == 'n' ? p->me.y - taby : p->me.x - tabx) - 1, i, s);
	else
		display(p, s == 's' ? taby - p->me.y : tabx - p->me.x, i, s);
}
