/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 17:09:51 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/29 20:35:04 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "init.h"
#include "debug.h"

/* TODO CHECKER ERREUR PARSING 1.lmin && 3.lmin file */
/* TODO GERER LES FUITES MEMOIRES */

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
		print_jams(lemin->jam);/*_DEBUG_*/
		ft_putstr("--------------------------------------------------\n\n");/*_DEBUG_*/
		get_comb_set(lemin);
//		ft_putstr("--------------------------------------------------\n\n");/*_DEBUG_*/
//		print_jams(lemin->comb);
//		ft_putstr("--------------------------------------------------\n\n");/*_DEBUG_*/
		print_type("nombre de chemin", &lemin->i_tmp, INT);
		print_type("nombre de fourmis", &lemin->ant_nbr, INT);
		print_type("nombre de coups", &lemin->size, INT);
		print_listsp(lemin->sp_tmp);
			
//		MEMORY LEAKS
//		while (1);/*_DEBUG_*/
	}
	return (EXIT_SUCCESS);
}
