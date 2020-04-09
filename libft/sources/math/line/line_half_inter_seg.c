/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_half_inter_seg.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 23:23:07 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 10:39:31 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	line_half_inter_seg(t_half_line l, t_seg s, t_vec *result)
{
	float	d_s;
	float	d_l;
	float	d_s1;
	float	d_s2;

	if (!line_inter_line(line_create_point_vec(l.p, l.d), 	\
			line_create_points(s.a, s.b), result))
		return (0);
	d_l = vec_scale_product(vec_remove(*result, l.p), l.d);
	d_s = vec_norm(vec_remove(s.b, s.a));
	d_s1 = vec_norm(vec_remove(*result, s.a));
	d_s2 = vec_norm(vec_remove(*result, s.b));
	if (d_l < 0 || d_s1 > d_s || d_s2 > d_s)
		return (0);
	if (!d_l)
		return (2);
	if (d_s1 == d_s || d_s2 == d_s)
		return (3);
	return (1);
}
