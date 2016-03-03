/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolved.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 00:35:32 by bndao             #+#    #+#             */
/*   Updated: 2016/03/03 09:59:56 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/included.h"

static int			check_place(char **reso, t_tetri *s, t_point *p)
{
	int			i;
	t_point		**scheme;

	i = 0;
	if (s == NULL)
		return (0);
	scheme = get_point(s);
	while (i < 4)
	{
		if (p->c + scheme[i]->c - s->offset >= (int)ft_strlen(reso[0])
				|| p->l + scheme[i]->l >= (int)ft_strlen(reso[0]))
			return (0);
		if (reso[p->l + scheme[i]->l][p->c + scheme[i]->c - s->offset] != '.')
			return (0);
		i++;
	}
	return (1);
}

static void			write_tetri(char **reso, t_tetri *s, t_point *p)
{
	int			i;
	t_point		**scheme;

	scheme = get_point(s);
	i = 0;
	while (i < 4)
	{
		reso[p->l + scheme[i]->l][p->c + scheme[i]->c - s->offset] = s->letter;
		i++;
	}
}

int					tetri_in(char **reso, t_tetri *s, int x, int y)
{
	t_point		*point_r;

	if ((point_r = (t_point *)malloc(sizeof(t_point))) != NULL)
	{
		point_r->l = y;
		while (reso[point_r->l])
		{
			point_r->c = x;
			while (reso[point_r->l][point_r->c])
			{
				if (reso[point_r->l][point_r->c] == '.')
				{
					if (check_place(reso, s, point_r) == 1)
					{
						write_tetri(reso, s, point_r);
						return (1);
					}
				}
				point_r->c++;
			}
			point_r->l++;
		}
	}
	return (0);
}

static void			ft_delete(char **tab, char chr)
{
	int			x;
	int			y;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == chr)
				tab[y][x] = '.';
			++x;
		}
		++y;
	}
}

short				ft_backtrack(t_tetri *l, char **tab)
{
	int			x;
	int			y;

	if (!l)
		return (0);
	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tetri_in(tab, l, x, y) && !ft_backtrack(l->next, tab))
				return (0);
			ft_delete(tab, l->letter);
			x++;
		}
		++y;
	}
	return (1);
}
