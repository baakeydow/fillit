/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:27:21 by bndao             #+#    #+#             */
/*   Updated: 2016/03/03 08:27:37 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/included.h"

static char			**allocate(char **tetri, char *map)
{
	int			i;
	int			size;
	char		**tetri_ok;

	i = 0;
	size = ft_count_splits(map);
	if (!(tetri_ok = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	tetri_ok[size] = NULL;
	while (tetri[i])
	{
		if (!check_tetri(tetri[i]))
			ft_error();
		tetri_ok[i] = mv_up(mv_left((tetri[i])));
		i++;
	}
	return (tetri_ok);
}

static char			**checking(char *av_1)
{
	char		*map;
	char		**tetri;
	char		**ok;

	map = get_map(av_1);
	if (!checked(map))
		ft_error();
	tetri = ft_split_map(map);
	if (!(tetri))
		ft_error();
	ok = allocate(tetri, map);
	if (!ok)
		ft_error();
	ft_memdel((void **)tetri);
	return (ok);
}

int					main(int ac, char **av)
{
	int			i;
	char		**ok;
	t_tetri		*start;
	t_mylist	*mylist;

	i = 1;
	if (!(mylist = (t_mylist *)malloc(sizeof(t_mylist))))
		return (0);
	if (ac != 2)
		ft_error();
	ok = checking(av[1]);
	start = t_new(m_tetri(ok[0]), 'A');
	mylist->begin = start;
	while (ok[i])
	{
		push_back(start, t_new(m_tetri(ok[i]), (i + 'A')));
		i++;
	}
	start = mylist->begin;
	letters_in(start);
	start = mylist->begin;
	ft_call(start, av[1], mylist);
	return (0);
}
