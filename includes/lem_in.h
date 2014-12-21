/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 18:13:52 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/14 03:44:45 by bmbarga          ###   ########.fr       */
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

typedef	unsigned long	t_ulong;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;

}					t_list;

typedef	struct		s_hash
{
	t_ulong			h1;
//	t_ulong			h2;
	char			*name;
}					t_hash;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;


typedef struct	s_nod
{
	char		*name;
	t_coord		*coord;
	t_hash		*links;
	int			props; //proprites du noeuds
}				t_nod;

typedef struct	s_lemin
{
	int		ant_nbr;
	t_list	**hashtab; //table de hash stocke list de noeuds correspondant a un hash donnee.
	int		data_type;
}				t_lemin;

/*
** get_data.c
*/

void	treat_line(t_lemin *lemin, char *str);
int		get_data(t_lemin *lemin);
#endif
