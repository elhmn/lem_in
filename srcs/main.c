/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 17:09:51 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/14 03:47:56 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "init.h"
#include "debug.h"

/*
**	1- recuperer les donnees sur l'entree standard
**	2- checker les cas sensibles d'erreur
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
	debug_lemin(lemin);
	if (ac)
	{
		get_data(lemin);
	//	debug_lemin(lemin);
		//treat data
		//print_data
	}
	return (0);
}
