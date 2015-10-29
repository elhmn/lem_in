/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 18:13:52 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/29 14:16:35 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "lib.h"
# include "check_errors.h"
# include "get_next_line.h"
# include "hotrace.h"

/*
** enum de commande
*/

enum	e_props
{
	START,
	END
};

enum	e_data_type
{
	ANTS_NBR,
	ROOMS,
	TUBES
};

typedef unsigned long	t_ulong;

typedef	struct			s_hash
{
	t_ulong			h1;
	char			*name;
}						t_hash;

typedef struct			s_coord
{
	int			x;
	int			y;
}						t_coord;

typedef struct s_list	t_list;
typedef struct s_listsp	t_listsp;
typedef struct s_jam	t_jam;
typedef struct s_uplet	t_uplet;

typedef struct			s_nod
{
	char				*name;
	t_coord				coord;
	t_list				*links;
	int					bool;
	int					index;
	int					props;
}						t_nod;

struct					s_list
{
	t_nod				*nod;
	t_list				*next;
};

struct					s_jam
{
	t_nod				*nod;
	t_listsp			*pathsp;
	t_jam				*next;
};

struct					s_listsp
{
	t_list				*list;
	int					path_len;
	int					a;
	int					index;
	t_listsp			*next;
};


/*
** s_uplet declaration:
** l --> longueur du chemin.
** a --> nombre de fourmis envoyees sur le chemin.
** p --> chemin emprunte.
*/

struct				s_uplet
{
	int				l;
	int				a;
	int				index; // use unknown
	t_list			*p; // maybe use t_listsp
};

/*
** lemin->set est l'ensemble solution definit comme suit:
** lemin->set = {(A_i, P_i, L_i) / i E [0, +inf] nombre entier}
** ou C_i est le i-eme chemin de longueur L_i et A_i
** le i-eme nombre de fourmis envoyees sur le chemin P_i
*/

typedef struct			s_lemin
{
	int			ant_nbr;
	int			room_nbr;
	int			props;
	int			data_type;
	int			path_len;
	int			len_tmp;
	char		*end_name;
	int			path_nbr;
	t_list		**hashtab;
	t_nod		*start;
	t_list		*path;
	t_listsp	*pathsp;
	t_list		*chemin;
	t_uplet		*set;
	t_nod		*end;
	int			i_tmp;
	t_jam		*jam;
	t_jam		*comb;
	int			size;
	t_listsp	*sp_tmp;
}						t_lemin;

/*
** avoid_traffic_jams.c
*/

void		print_jam(t_jam *jam, int size);
void		print_jams(t_jam *jam);

/*
** check_path.c
*/

int		check_path(t_listsp *p1, t_listsp *p2);

/*
** get_comb_set.c
*/

void		add_copy_comb_tmp(t_jam **comb, t_jam *comb_tmp);
void		get_comb_set(t_lemin *lemin);
t_listsp	*new_listsp_from_listsp(t_listsp **sp, t_listsp *listsp);
void		print_firstsp(t_listsp *sp);

/*
** get_set.c
*/

int						get_set(t_lemin *lemin);

/*
** get_data.c
*/

void					treat_line(t_lemin *lemin, char *str);
int						get_data(t_lemin *lemin);
void					get_rooms(t_lemin *lemin, char *str);
void					get_ants(t_lemin *lemin, char *str);

/*
** get_data_tools1.c
*/

int						is_room(char *str, t_lemin *lemin);
int						is_tube(char *str, t_lemin *lemin);
void					get_room_data(char *str, t_lemin *lemin);
void					hashtab_addelem(t_lemin *lemin, t_nod *nod);
int						hashtab_chr(t_list **hashtab, void *data);

/*
** get_data_tools2.c
*/

void					add_link(t_nod *nod1, t_nod *nod2);
void					nod_addelem(t_nod *nod1, t_nod *nod2);
t_nod					*if_match(char *str, t_list **hashtab, int nod);
void					get_props(t_lemin *lemin, t_nod *nod);

/*
** pathfinder.c
*/

t_nod					*pathfinder(t_nod *nod, t_lemin *lemin, t_jam *jam);
void					print_list(t_list *list);

/*
** find_path.c
*/

void					print_listsp(t_listsp *listsp);
void					get_paths(t_lemin *lemin);
void					reset_data(t_lemin *lemin);

/*
** avoid_traffic_jams.c
*/

void					avoid_trafjams(t_listsp *pathsp, t_lemin *lemin);

/*
** correct_path.c
*/

int						correct_path(t_lemin *lemin, t_jam **jam);
int						modify_path(t_jam *jam, t_listsp *tmpsp, t_lemin *lemin);
t_nod					*get_start_nod(t_list *list, t_nod *nod);

/*
** correct_path_tools.c
*/

void					sort_listsp(t_listsp *listsp);
void					swap_listsp(t_listsp *list1, t_listsp *list2);
void					reset_nod_state(t_list *list, t_nod *end);
void					set_nod_state(t_list *list, t_nod *end);
void					add_new_path(t_list **path, t_nod *start, t_lemin *lemin);

#endif
