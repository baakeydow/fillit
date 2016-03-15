/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 11:02:07 by bndao             #+#    #+#             */
/*   Updated: 2016/03/02 00:29:44 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <included.h>

static int			check_if(char *s, size_t j)
{
	int			d;

	d = 0;
	if (s[j] == '#')
	{
		if (s[j - 1] == '#')
			d++;
		if (j + 1 < ft_strlen(s) && s[j + 1] == '#')
			d++;
		if (s[j - 5] == '#')
			d++;
		if (j + 5 < ft_strlen(s) && s[j + 5] == '#')
			d++;
	}
	return (d);
}

int					check_tetri(char *s)
{
	size_t		j;
	int			d;
	size_t		p[3];

	d = 0;
	p[0] = 0;
	p[1] = 0;
	p[2] = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == '.')
			p[0]++;
		if (s[j] == '#')
			p[1]++;
		if (s[j] == '\n')
			p[2]++;
		d += check_if(s, j);
		j++;
	}
	if (p[0] != 12 || p[1] != 4 || p[2] != 3 || d < 6)
		return (0);
	return (1);
}

int					checked(char *s)
{
	size_t		j;

	j = 0;
	while (s[j])
	{
		if (s[j] != '.' && s[j] != '#' && s[j] != '\n')
			ft_error();
		j++;
	}
	if (!check_d_line(s))
		ft_error();
	if (s[ft_strlen(s) - 2] == '\n')
		ft_error();
	return (1);
}

static int			ft_sqrt(int nb)
{
	int			i;

	i = 1;
	if (nb == 1)
		return (1);
	else if (nb <= 0)
		return (0);
	while (nb > (i * i))
		i++;
	return (i);
}

int					s_opti(char *map)
{
	int			opt_n;

	opt_n = 2 * ft_sqrt(ft_count_splits(map));
	return (opt_n);
}
