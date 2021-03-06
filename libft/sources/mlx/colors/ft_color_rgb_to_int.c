/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_color_rgb_to_int.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 15:25:36 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 10:42:44 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_color_rgb_to_int(t_rgb rgb)
{
	return ((rgb.r << 16) + (rgb.g << 8) + rgb.b);
}
