/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 16:29:52 by mnguyen           #+#    #+#             */
/*   Updated: 2015/10/28 16:34:09 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** calc.c
*/

typedef struct	s_struct t_struct;
struct			s_struct
{
    int f_t;
    int s_t;
    int n;
};

int				calc(t_listsp *pathsp, int a_t);
void			calc_f1(t_listsp *pathsp, t_struct *c);
void			calc_a(t_listsp *pathsp, t_struct *c, int a_t);
void			add(t_listsp *pathsp, int i);
void			sous(t_listsp *pathsp);

/*
** sort.c
*/

int				list_len(t_listsp *pathsp);
void			sort(t_listsp **pathsp);
t_listsp		*swap(t_listsp *last, t_listsp *s1, t_listsp *s2, t_listsp **pathsp);

/*
** aff.c
*/

void			aff_moove(int f, char *s, int *bool);
void			aff_path(t_list *path, int a, int b, int *bool);
void			aff_line(t_listsp *pathsp, int *a);
void			set_index(t_listsp *pathsp);
void			aff(t_listsp *pathsp, int t_a);
