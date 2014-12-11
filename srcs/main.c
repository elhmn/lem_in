/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 17:09:51 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/11 21:13:11 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	1- recuperer les donner sur l'entree standard
**	2- checker les cas sensibles d'erreur
**	3- rechercher le chemin le plus rapide
**	4- affichage du resultat.
*/

int		main(int ac, char **av)
{
	int	fd;

	if (ac == 1)
		fd = 0;	
	else
	{
		if ((fd = open(av[0], O_RDONLY)) == -1)
			check_errors(MALLOC, "fd", "main.c");
		if (ac > 2)
			ft_putendl("lem-in cant treat on more than 1 file");
	}
	return (0);
}