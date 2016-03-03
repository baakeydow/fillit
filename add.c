/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:40:54 by bndao             #+#    #+#             */
/*   Updated: 2016/03/03 09:58:42 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/included.h"

char					**make_map(int n)
{
	int			i;
	char		**map;

	i = 0;
	map = NULL;
	if (!(map = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	map[n] = NULL;
	while (i < n)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * n + 1)))
			return (NULL);
		ft_memset(map[i], '.', n);
		map[i][n] = '\0';
		i++;
	}
	return (map);
}

void					ft_call(t_tetri *l, char *av1, t_mylist *b)
{
	char		**tab;
	int			n;
	int			i;

	n = s_opti(get_map(av1));
	tab = make_map(n - 1);
	i = ft_count_splits(get_map(av1));
	while (ft_backtrack(l, tab))
	{
		if (i == 1)
		{
			tab = make_map(n++);
			i = ft_count_splits(get_map(av1));
			l = b->begin;
		}
		l = swap_loop(l, b);
		i--;
	}
	n = 0;
	while (tab[n])
		ft_putendl(tab[n++]);
}

void					swap_elem_data(t_tetri *elem1, t_tetri *elem2)
{
	t_tetri		tmp;

	tmp.tetri = elem1->tetri;
	elem1->tetri = elem2->tetri;
	elem2->tetri = tmp.tetri;
	tmp.letter = elem1->letter;
	elem1->letter = elem2->letter;
	elem2->letter = tmp.letter;
	tmp.offset = elem1->offset;
	elem1->offset = elem2->offset;
	elem2->offset = tmp.offset;
}

t_tetri					*swap_loop(t_tetri *start, t_mylist *mylist)
{
	t_tetri		*nextone;

	start = mylist->begin;
	nextone = start->next;
	while (start && start->next != NULL)
	{
		swap_elem_data(start, nextone);
		start = start->next;
		nextone = nextone->next;
	}
	nextone = mylist->begin;
	start = mylist->begin;
	return (start);
}
