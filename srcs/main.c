/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 17:09:51 by bmbarga           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2014/12/14 03:27:49 by bmbarga          ###   ########.fr       */
=======
/*   Updated: 2014/12/11 21:13:11 by bmbarga          ###   ########.fr       */
>>>>>>> 79fd08cf1376cd5f6086389554095c382d48d8e2
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	1- recuperer les donnees sur l'entree standard
**	2- checker les cas sensibles d'erreur
**	3- rechercher les chemins les plus rapides (djikstra)
**		-stocker les nbrs de fourmis -1 chemins possible
**		dans l'ordre croissant
**		-identifier les chemins direct
**		-reflechir a la priorite avec bouchon
**	4- Find nbrs de coups optimal.
**	5- affichage du resultat.
*/

int		main(int ac, char **av)
{
<<<<<<< HEAD

	if (ac)	
	{
		ft_putendl(av[1]);
		ft_putendl("lem-in cant treat on more than 1 file");
=======
	int	fd;

	if (ac == 1)
		fd = 0;	
	else
	{
		if ((fd = open(av[0], O_RDONLY)) == -1)
			check_errors(MALLOC, "fd", "main.c");
		if (ac > 2)
			ft_putendl("lem-in cant treat on more than 1 file");
>>>>>>> 79fd08cf1376cd5f6086389554095c382d48d8e2
	}
	return (0);
}
