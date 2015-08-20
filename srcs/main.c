/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 17:09:51 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/02 14:54:01 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "init.h"
#include "debug.h"

/*
**	1- recuperer les donnees sur l'entree standard		DONE
**	2- checker les cas sensibles d'erreur		DONE
**	3- rechercher les chemins les plus rapides par branches (djikstra or A* algorithms)		DONE
**		-stocker les chemins possibles dans l'ordre croissant (longueur)					SUPPRIMMER
**		-identifier les chemins directes (pas necessaire pour le moment)					SUPPRIMER
**		(plutard)-reflechir a la priorite avec bouchon										DEJA FAIT
**	4- Find les coups a jouer (optimal). en determinant les F_nb pow(C_nb) ensembles de coups possible.
**	5- affichage du resultat.
*/

//check_that end nod is different than start nod

int		main(int ac, char **av)
{
	t_lemin		*lemin;

	(void)av;
	lemin = NULL;
	lemin = init_lemin(lemin);
	if (ac)
	{
		get_data(lemin);
		lemin->start->bool = TRUE;
		get_paths(lemin);
		print_listsp(lemin->pathsp);
		ft_putendl("\n\n\n\n\n");
		avoid_trafjams(lemin->pathsp, lemin);
//		debug_lemin(lemin); /*_DEBUG_*/


//		pathfinder(lemin->start->links->nod, lemin);
//		print_type("lemin->start->links->nod", lemin->start->links->nod->name, CHAR);/*_DEBUG_*/
//		print_list(lemin->path);/*_DEBUG_*/
//		print_type("lemin->start->links->next->nod", lemin->start->links->next->nod->name, CHAR);/*_DEBUG_*/
//		pathfinder(lemin->start->links->next->nod, lemin);
//		print_list(lemin->path);/*_DEBUG_*/
/*
** pour checker si il est possible de trouver un chemin il suffira de verifier que
** lemin->paths != NULL ou existe
*/
//		pathfinder(lemin->start, lemin);
//		print_list(lemin->path);/*_DEBUG_*/
//		print_listsp(lemin->pathsp);/*_DEBUG_*/
//		print_type("lemin->path_len", &(lemin->path_len), INT);/*_DEBUG_*/
//		ft_putendl("debug start :: "); /*_DEBUG_*//*_DEBUG_*/
//		debug_nod(lemin->start);/*_DEBUG_*/
//		ft_putendl("debug end :: "); /*_DEBUG_*//*_DEBUG_*/
///		debug_nod(lemin->end);/*_DEBUG_*/
//		print_hashtab(lemin->hashtab);/*_DEBUG_*/
//		treat data/*_DEBUG_*/
//		print_data/*_DEBUG_*/
	}
	return (0);
}
