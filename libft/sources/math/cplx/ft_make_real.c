/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_make_real.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 15:10:33 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 10:59:17 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_real	ft_make_real(int x, int y)
{
	t_real	r;

	r.x = x;
	r.y = y;
	return (r);
}