/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 16:04:09 by bndao             #+#    #+#             */
/*   Updated: 2016/03/13 23:01:03 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <included.h>

void			get_point(t_tetri *s, t_point scheme[4])
{
	int				l;
	int				c;
	int				i;

	i = 0;
	l = 0;
	while (l < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (s->tetri[l][c] == s->letter)
			{
				scheme[i].l = l;
				scheme[i].c = c;
				i++;
			}
			c++;
		}
		l++;
	}
}
