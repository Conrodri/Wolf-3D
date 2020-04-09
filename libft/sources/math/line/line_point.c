/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_point.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 22:46:15 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 22:46:40 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_vec	line_point(t_line l)
{
	return (vec_create(l.x.o, l.y.o, l.z.o));
}