/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 17:09:51 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/26 21:44:33 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "init.h"
#include "debug.h"

/* TODO CHECKER ERREUR PARSING 1.lmin file */


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

/*
** Nouvel algo:
*/

/*
** 1- Trouver tous les chemins possibles (par branche).
** 2- Trouver toutes les combinaisons de chemins possible.
** 3- Trouver les combinaisons de chemins non secant.
** ---- Trouver puis comparer le temps de chacunes des combinaisons trouvees.
** 4- Si aucune combinaison de chemin non secant n'est trouvee.
** ---- Traiter chacunes des combinaisons pour eliminer les chemins surperflus.
** ---- Trouver puis comparer le temps de chacunes des combinaisons trouvees.
*/

//check_that end nod is different than start nod

int		main(int ac, char **av)

	t_lemin		*lemin;

	(void)av;
	lemin = NULL;
	lemin = init_lemin(lemin);
	if (ac)
	{
		get_data(lemin);
		lemin->start->bool = TRUE;
//		modifier get_path au besoin du pt 1 de l'algo.
//		il devra trouver tous les chemins possible.
		get_paths(lemin);
		print_jams(lemin->jam);/*_DEBUG_*/

//		modifier get_set au besoin du pt 2 de l'algo.
//		il devra trouver toutes les combinaisons de
//		chemin possible.

//		get_sets(lemin);

//		trouver les combinaisons de chemins non secant.
//		get_nosecpaths(lemin);

//		calculer puis comparer le T des combiasons trouvees.
//		get_finalset(lemin);

//		if (nosecpath founded)
//			Traiter chacune des combinaisons pour eliminer
//			les chemin superflu.
//			treat_setpaths(lemin);

//		calculer puis comparer le T des combiasons trouvees.
//		get_finalset(lemin);

//		print_result(lemin->set);

/*
** pour checker si il est possible de trouver un chemin il suffira de verifier que
** lemin->paths != NULL ou existe
*/

//		treat data()/*_DEBUG_*/
//		print_data()/*_DEBUG_*/
	}
	return (EXIT_SUCCESS);
}
