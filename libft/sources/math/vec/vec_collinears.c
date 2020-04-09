/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vec_collinears.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 22:47:18 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 15:38:39 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

inline int	vec_collinears(t_vec u, t_vec v)
{
	float	k;

	if (v.x)
		k = u.x / v.x;
	else if (v.y)
		k = u.y / v.y;
	else if (v.z)
		k = u.z / v.z;
	else
		return (1);
	return (u.x == k * v.x && u.y == k * v.y && u.z == k * v.z);
}
