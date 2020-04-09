/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vec_remove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 19:43:29 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 12:08:06 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

inline t_vec	vec_remove(t_vec u, t_vec v)
{
	t_vec	r;

	r.x = u.x - v.x;
	r.y = u.y - v.y;
	r.z = u.z - v.z;
	return (r);
}
