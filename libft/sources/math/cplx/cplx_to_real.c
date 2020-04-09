/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cplx_to_real.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 10:26:51 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 10:28:26 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_real	cplx_to_real(t_cplx z)
{
	t_real	r;

	r.x = z.rl;
	r.y = z.im;
	return (r);
}