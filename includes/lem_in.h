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

/*
** enum de commande
*/

enum	e_com
{
	START,
	END
};

typedef struct	s_lemin
{
	int		ant_nbr;
	//nbr de cases;
	//liste de cases et de leurs coordonnees;
}				t_lemin;

//typedef struct	s_room
//{
//	char 	*name;
//	t_room	**room;
//}				t_room;

//typedef	struct	s_data
//{
//	char	*data;
//	int		com; /*commande*/
//}				t_data;
	//liste des commandes;
	//liste des coups ou chaine dans l'ordre;
//}				t_lemin

typedef	struct	s_data
{
	char	*data;
	int		com; /*commande*/
}				t_data;

#endif
