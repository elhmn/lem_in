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
**	4- Creer nouveau fichiers de test.
**	5- Tester le lemin.
**		-- Bug tubes declares avant ou entre deux declarations de noeuds
**	6- Implementer l'algo
**		-- algo
**			-- Implementer la boucle.
**			-- Calcul de couts. 
**			-- Comparer couts_min avec couts_courant.
**			-- Conserver l'ensemble correspondant.
**		-- Generer la sortie.
**	7- Mise a la norme.
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
		if (!lemin->pathsp)
			error("No paths founded !! :(\n");
		print_listsp(lemin->pathsp);/*_DEBUG_*/
		get_set(lemin);
//		print_result(lemin->set);

/*
** pour checker si il est possible de trouver un chemin il suffira de verifier que
** lemin->paths != NULL ou existe
*/

//		treat data/*_DEBUG_*/
//		print_data/*_DEBUG_*/
	}
	return (EXIT_SUCCESS);
}
