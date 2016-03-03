/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 11:11:14 by bndao             #+#    #+#             */
/*   Updated: 2016/03/03 09:58:45 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/included.h"

char				*mv_left(char *t)
{
	int			i;
	int			j;

	j = 0;
	while (j <= 2)
	{
		i = 0;
		if (t[0] == '.' && t[5] == '.' && t[10] == '.' && t[15] == '.')
			while (t[i])
			{
				if (t[i] == '#' && t[i - 1] == '.')
				{
					t[i] = '.';
					t[i - 1] = '#';
				}
				i++;
			}
		j++;
	}
	return (t);
}

char				*mv_up(char *t)
{
	int			i;
	int			j;

	j = 0;
	while (j <= 2)
	{
		i = 0;
		if (t[0] == '.' && t[1] == '.' && t[2] == '.' && t[3] == '.')
			while (t[i])
			{
				if (t[i] == '#' && t[i - 5] == '.')
				{
					t[i] = '.';
					t[i - 5] = '#';
				}
				i++;
			}
		j++;
	}
	return (t);
}

int					set(char **tetri)
{
	if (tetri[0][0] == '.' && tetri[0][1] == '.')
		return (2);
	if (tetri[0][0] == '.')
		return (1);
	return (0);
}

int					check_d_line(char *s)
{
	int i;
	int t;
	int lim;

	t = 0;
	i = 21;
	lim = ft_count_splits(s);
	if (lim == 1 && ft_strlen(s) > 20)
		return (0);
	while (t < lim - 1 && s[i])
	{
		if (s[i] == '\n' && s[i - 1] != '\n' && s[i + 5] != '\n')
			return (0);
		i += 21;
		t++;
	}
	return (1);
}
