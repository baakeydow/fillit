/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:45:46 by bndao             #+#    #+#             */
/*   Updated: 2016/02/08 03:44:29 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <included.h>

void				ft_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

char				**m_tetri(char *str)
{
	char	**s_tetri;

	s_tetri = ft_strsplit(str, '\n');
	return (s_tetri);
}

t_tetri				*t_new(char **tetri, char letter)
{
	t_tetri		*node;

	if (!(node = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	node->letter = letter;
	node->tetri = tetri;
	node->offset = set(tetri);
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void				push_back(t_tetri *b_list, t_tetri *list)
{
	t_tetri		*tmp;

	if (b_list == NULL)
		b_list = list;
	else
	{
		tmp = b_list;
		while (tmp->next)
			tmp = tmp->next;
		list->prev = tmp;
		list->next = NULL;
		tmp->next = list;
	}
}

void				letters_in(t_tetri *s)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (s)
	{
		i = 0;
		while (s->tetri[i])
		{
			j = 0;
			while (s->tetri[i][j])
			{
				if (s->tetri[i][j] == '#')
					s->tetri[i][j] = s->letter;
				j++;
			}
			i++;
		}
		s = s->next;
	}
}
