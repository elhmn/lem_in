/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 17:09:51 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/30 03:22:54 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "init.h"
#include "debug.h"

/*
** TODO CHECKER ERREUR PARSING 1.lmin && 3.lmin file
** TODO GERER LES FUITES MEMOIRES
** AFFICHER fichier
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

/*
** check_that end nod is different than start nod
*/

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
		get_comb_set(lemin);
		aff(lemin->sp_tmp, lemin->size);
	}
	return (EXIT_SUCCESS);
}
