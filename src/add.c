/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:40:54 by bndao             #+#    #+#             */
/*   Updated: 2016/03/08 04:18:38 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <included.h>

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

void					ft_call(t_tetri *l)
{
	char		**tab;
	int			n;

	n = 2;
	tab = make_map(n);
	while (ft_backtrack(l, tab))
		tab = make_map(++n);
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
