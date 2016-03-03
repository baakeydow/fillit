/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   included.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:41:06 by bndao             #+#    #+#             */
/*   Updated: 2016/03/03 08:27:34 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INCLUDED_H
# define FT_INCLUDED_H
# define BUFFSIZE 10
# define SPLITSIZE 21
# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct			s_tetri
{
	char				**tetri;
	char				letter;
	int					offset;
	struct s_tetri		*next;
	struct s_tetri		*prev;
}						t_tetri;

typedef struct			s_point
{
	int					l;
	int					c;
}						t_point;

typedef struct			s_mylsit
{
	t_tetri				*begin;
}						t_mylist;

char					*get_map(char *str);
int						ft_count_splits(char *s);
char					**ft_split_map(const char *s);
int						checked(char *s);
int						check_tetri(char *s);
void					ft_error(void);
char					*mv_up(char *t);
char					*mv_left(char *t);
char					**m_tetri(char *str);
t_tetri					*t_new(char **tetri, char letter);
void					letters_in(t_tetri *s);
void					push_back(t_tetri *b_list, t_tetri *list);
int						s_opti(char *map);
char					**make_map(int n);
int						tetri_in(char **reso, t_tetri *s, int x, int y);
t_point					**get_point(t_tetri *s);
short					ft_backtrack(t_tetri *s, char **tab);
void					ft_call(t_tetri *l, char *av1, t_mylist *mylist);
int						check_d_line(char *s);
int						set(char **tetri);
void					swap_elem_data(t_tetri *el1, t_tetri *el2);
t_tetri					*swap_loop(t_tetri *start, t_mylist *mylist);

#endif
