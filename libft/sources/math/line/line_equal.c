/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_equal.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 22:49:00 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 10:38:43 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	line_equal(t_line l1, t_line l2)
{
	return (vec_collinears(line_vec_dir(l1), line_vec_dir(l2)) && 		\
			vec_collinears(vec_remove(line_point(l1), line_point(l2)), 	\
			line_vec_dir(l2)));
}
