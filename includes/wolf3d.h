/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 01:19:53 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/05 14:55:26 by conrodri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef WOLF3D_H
# define WOLF3D_H
# include "../libft/includes/libft.h"
# include "keys.h"
# include "struct.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# define WIDTH 1920
# define HEIGHT 1080
# define FOV 60
# define COLOR_RED "\x1b[31m"
# define COLOR_GREEN "\x1b[32m"
# define COLOR_BLUE "\x1b[34m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_CYAN "\x1b[36m"
# define COLOR_DARKGRAY "\e[37;2m"
# define COLOR_RESET "\x1b[0m"
# define FLOOR 0xFFE400
# define CEILLING 0x00BFFF

void	display(t_param *p, float dist, int x, char side);
void	algo(t_param *p);
void	check_n_s_e_o(t_param *p, int i, char s);
void	check_no(t_param *p, int i);
void	check_ne(t_param *p, int i);
void	check_so(t_param *p, int i);
void	check_se(t_param *p, int i);
int		get_size_map(t_param *p, t_wolf *wolf, int i, int len);
char	**create_char_map(t_wolf *wolf, int *fd);
int		**get_int_map(t_param *p, t_wolf *wolf, int i);
int		place_player(t_param *p);
int		check_valid_map(t_param *p);
void	ft_split_tab(char *tmp, t_wolf *wolf, t_param *p);
int		mouse_movement(int x, int y, struct s_param *p);

#endif
