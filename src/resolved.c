/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolved.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 00:35:32 by bndao             #+#    #+#             */
/*   Updated: 2016/03/13 23:18:24 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <included.h>

static void			write_tetri(char **reso, t_tetri *s, t_point *p)
{
	int			i;
	t_point		scheme[4];

	get_point(s, scheme);
	i = 0;
	while (i < 4)
	{
		reso[p->l + scheme[i].l][p->c + scheme[i].c - s->offset] = s->letter;
		i++;
	}
}

int					tetri_in(char **reso, t_tetri *s, int y, int x)
{
	t_point		p;
	t_point		scheme[4];
	int			i;

	get_point(s, scheme);
	i = -1;
	p.l = y;
	p.c = x;
	while (++i < 4)
	{
		if (p.c + scheme[i].c - s->offset >= (int)ft_strlen(reso[0])
				|| p.l + scheme[i].l >= (int)ft_strlen(reso[0]))
			return (0);
		if (reso[y + scheme[i].l][x + scheme[i].c - s->offset] != '.')
			return (0);
	}
	write_tetri(reso, s, &p);
	return (1);
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
			if (tetri_in(tab, l, y, x))
			{
				if (!ft_backtrack(l->next, tab))
					return (0);
				ft_delete(tab, l->letter);
			}
			++x;
		}
		++y;
	}
	return (1);
}
