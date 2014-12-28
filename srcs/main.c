/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 17:09:51 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/28 17:27:09 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "init.h"
#include "debug.h"

/*
**	1- recuperer les donnees sur l'entree standard		DONE
**	2- checker les cas sensibles d'erreur		DONE
**	3- rechercher les chemins les plus rapides par branches (djikstra or A* algorithms)
**		-stocker les chemins possibles dans l'ordre croissant (longueur)
**		-identifier les chemins directes (pas necessaire pour le moment)
**		(plutard)-reflechir a la priorite avec bouchon
**	4- Find les coups a jouer (optimal). en determinant les F_nb pow(C_nb) ensembles de coups possible.
**	5- affichage du resultat.
*/

int		main(int ac, char **av)
{
	t_lemin		*lemin;

	av = av;
	lemin = NULL;
	lemin = init_lemin(lemin);
	if (ac)
	{
		get_data(lemin);
		lemin->start->bool = 1;
		lemin->path_len = 0;
		lemin->len_tmp = 0;
		lemin->chemin = NULL;
		pathfinder(lemin->start, lemin, lemin->start);
//		print_list(lemin->path);
		print_type("lemin->path_len", &(lemin->path_len), INT);
//		ft_putendl("debug start :: "); /*****/
//		debug_nod(lemin->start);
//		ft_putendl("debug end :: "); /*****/
///		debug_nod(lemin->end);
//		print_hashtab(lemin->hashtab);
//		debug_lemin(lemin); /***************/
		//treat data
		//print_data
	}
	return (0);
}
