/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/07 15:56:07 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 11:15:26 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		free(map[i]);
		map[i] = NULL;
	}
	free(map);
}

static char		*clean_join(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(ret = (char *)malloc(sizeof(char)			\
					* ft_strlen(s1) + ft_strlen(s2) + 2)))
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
		exit(0);
	}
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\n';
	ret[i + 1] = '\0';
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (ret);
}

static int		**ft_feed_tab(t_param *p, t_wolf *wolf, int i)
{
	char	tmp[11];

	wolf->j = 0;
	wolf->k = 0;
	wolf->i = i;
	if (!(p->map = (int**)malloc(sizeof(int*) * p->sizey)))
		return (NULL);
	while (wolf->map[++wolf->i] && !(wolf->l = 0))
	{
		if (!(p->map[wolf->i] = (int*)malloc(sizeof(int) * (p->sizex))))
			return (NULL);
		ft_split_tab(tmp, wolf, p);
		while (wolf->l < p->sizex)
			p->map[wolf->i][wolf->l++] = 0;
		wolf->j = 0;
	}
	return (p->map);
}

char			**create_char_map(t_wolf *wolf, int *fd)
{
	int		i;
	int		j;
	int		gnl;
	char	*ret;
	char	**map;

	i = 0;
	j = 0;
	gnl = 0;
	map = NULL;
	ret = ft_strdup(" ");
	while (get_next_line(*fd, &(wolf->line)))
	{
		gnl = 1;
		ret = clean_join(ret, wolf->line);
	}
	map = ft_strsplit(ret, '\n');
	free(ret);
	free(wolf->line);
	if (!(gnl))
		ft_error("gnl cannot malloc this map");
	return (map);
}

int				**get_int_map(t_param *p, t_wolf *wolf, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	p->map = ft_feed_tab(p, wolf, i);
	free_map(wolf->map);
	free(wolf);
	if (place_player(p) == -1)
		ft_error("Player has bad position");
	return (p->map);
}
