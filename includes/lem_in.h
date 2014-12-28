/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 18:13:52 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/28 16:18:09 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

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

typedef struct			s_nod
{
	char				*name;
	t_coord				coord;
	t_list				*links;
	int					bool;
	int					props;
}						t_nod;

struct					s_list
{
	t_nod				*nod;
	t_list				*next;
};

struct					s_listsp
{
	t_list				*list;
	t_listsp			*next;
};

typedef struct			s_lemin
{
	int			ant_nbr;
	t_list		**hashtab;
	int			room_nbr;
	int			props;
	char		*end_name;
	t_nod		*start;
	t_list		*path;
	t_list		*chemin;
	t_nod		*end;
	int			data_type;
	int			path_len;
	int			len_tmp;
}						t_lemin;

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
t_nod					*if_match(char *str, t_list **hashtab);
void					get_props(t_lemin *lemin, t_nod *nod);

/*
** pathfinder.c
*/

t_nod					*pathfinder(t_nod *nod, t_lemin *lemin, t_nod *parent);
void					print_list(t_list *list);
#endif
