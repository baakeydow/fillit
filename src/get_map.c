/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 19:45:06 by bndao             #+#    #+#             */
/*   Updated: 2016/02/08 03:26:07 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <included.h>

static char			*ft_buffcat(char *s1, char *buf, int ret, int tmp)
{
	char	*s2;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (!(s2 = (char *)malloc(sizeof(char) * (tmp + ret + 1))))
		return (NULL);
	while (i != tmp)
	{
		s2[i] = s1[i];
		i++;
	}
	while (x < ret)
	{
		s2[i + x] = buf[x];
		x++;
	}
	s2[i + x] = '\0';
	if (tmp > 0)
		free(s1);
	return (s2);
}

char				*get_map(char *str)
{
	int		ret;
	int		tmp;
	int		fd;
	char	buf[BUFFSIZE];

	if (!str)
		ft_error();
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error();
	tmp = 0;
	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buf, BUFFSIZE);
		if (ft_strlen(buf) < 10)
			ft_error();
		str = ft_buffcat(str, buf, ret, tmp);
		tmp = tmp + ret;
	}
	close(fd);
	return (str);
}

int					ft_count_splits(char *s)
{
	int		nb;
	int		cmp;

	nb = 0;
	cmp = 0;
	while (s[nb])
	{
		while (s[nb] && (s[nb] != '\n'))
			nb++;
		if (s[nb] && s[nb + 1] == '\n')
			cmp++;
		while (s[nb] && (s[nb] == '\n'))
			nb++;
	}
	if (cmp == 0)
		return (1);
	return (cmp + 1);
}

static char			**ft_map_in(const char *s, int splits_nbr)
{
	int		i;
	int		nb;
	char	**tab;

	i = 0;
	nb = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (splits_nbr + 1))))
		return (NULL);
	tab[splits_nbr] = NULL;
	while (i < splits_nbr)
	{
		if (i == splits_nbr - 1)
			tab[i] = ft_strtrim(ft_strsub(s, nb, 20));
		else
			tab[i] = ft_strtrim(ft_strsub(s, nb, SPLITSIZE));
		if (!tab[i])
			return (tab);
		nb += SPLITSIZE;
		i++;
	}
	return (tab);
}

char				**ft_split_map(const char *s)
{
	char	**tab;
	int		splits_nbr;

	if (!s)
		return (NULL);
	splits_nbr = ft_count_splits((char *)s);
	if (splits_nbr > 26)
		ft_error();
	tab = ft_map_in(s, splits_nbr);
	return (tab);
}
