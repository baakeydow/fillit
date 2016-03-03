/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 16:04:09 by bndao             #+#    #+#             */
/*   Updated: 2016/01/27 00:15:24 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/included.h"

static t_point		**allocate(void)
{
	t_point			**scheme;
	int				i;

	i = 0;
	if ((scheme = (t_point **)malloc(sizeof(t_point *) * 5)))
	{
		scheme[4] = NULL;
		while (i < 4)
		{
			if (!(scheme[i] = (t_point *)malloc(sizeof(t_point))))
				return (NULL);
			i++;
		}
	}
	return (scheme);
}

t_point				**get_point(t_tetri *s)
{
	t_point			**scheme;
	int				l;
	int				c;
	int				i;

	i = 0;
	scheme = allocate();
	l = 0;
	while (l < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (s->tetri[l][c] == s->letter)
			{
				scheme[i]->l = l;
				scheme[i]->c = c;
				i++;
			}
			c++;
		}
		l++;
	}
	return (scheme);
}
