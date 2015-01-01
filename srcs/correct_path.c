/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 06:39:48 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/01 16:34:29 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

// je modifie les chemins secants en un point N ssi ils existe
// un moyen de les modifier

static t_jam	*get_jam_to_change(t_jam *jam, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (jam[i].path && jam[i].path->next)
			return (jam + i);
	}
	return (NULL); // no jam exist
}

t_nod			*get_start_nod(t_list *list, t_nod *nod)
{
	t_nod	*tmp;

	if (list && nod)
	{
		tmp = list->nod;
		while (list && list->nod != nod)
		{
			tmp = list->nod;
			list = list->next;
		}
		if (list && list->nod == nod)
			return (tmp);
	}
	return (NULL);
}

int			modify_path(t_jam *jam, t_listsp *tmpsp, t_lemin *lemin)
{
	t_nod *start;

	set_nod_state(tmpsp->list, jam->nod);
//	print_list_nod(tmpsp->list); /*******************/
	start = get_start_nod(tmpsp->list, jam->nod);
	ft_putendl("print start nod :: "); /***********************/
	debug_nod(start); /***************/
	reset_data(lemin); // for pathfinder
	pathfinder(start, lemin);
	ft_putendl("This is the new path TMP :: ");
	print_list(lemin->path);
	reset_nod_state(tmpsp->list, jam->nod);
	if (lemin->path)
	{
		tmpsp->path_len = tmpsp->path_len + lemin->path_len - 2;
		add_new_path(&(tmpsp->list), start, lemin);
		ft_putendl("This is the new path :: ");
		print_list(tmpsp->list);
		return (1);
	}
	else
		ft_putendl("Does not exist ##########");
	return (0);
}

//modifier la longueur du bordel

int				correct_path(t_lemin *lemin, t_jam *jam)
{
	t_listsp	*tmpsp;
	t_listsp	*firstsp;
	int			i;

	if (lemin && jam)
	{
		i = 0;
		if (!(jam = get_jam_to_change(jam, lemin->room_nbr)))
			return (0); // no path to modify

		ft_putendl("JAM");
		print_type("jam->nod->name", jam->nod->name, CHAR);
		print_type("jam->nod->index", &(jam->nod->index), INT);
		print_listsp(jam->path);

//		print_listsp(jam->path);/**********************/
		sort_listsp(jam->path);//classer le tableau en fonction de la longueur des chemins
		ft_putendl("\n\n\n\n\n");/**********************/
		ft_putendl("after sorted ::\n");/**********************/
		print_listsp(jam->path);/**********************/
		/*
		 * WARNING :: si les chemins ont la meme longueur
		 * la modification arbitraire ne marche pas il pourrait arriver que
		 * seul le chemin non choisit soit modifiable
		 *
		 * SOLUTION PROVISOIRE ::
		 * si je n'ai pu modifier aucun chemin je modifie le chemin de depart.
		 */
		firstsp = jam->path;
		tmpsp = jam->path->next;
		while (tmpsp)
		{
			ft_putendl("The path to change ::\n");/**********************/
			print_listsp(tmpsp);/**********************/
			i += modify_path(jam, tmpsp, lemin);
			tmpsp = tmpsp->next;
		}
		if ((!i)
			&& (firstsp->next->path_len == firstsp->path_len))
		{
			ft_putendl("modify path");
			ft_putendl("The path to change ::\n");/**********************/
			print_listsp(firstsp);/**********************/
			modify_path(jam, firstsp, lemin);
		}
		ft_putendl("\n\n\n\n\n");
		ft_putendl("This is the new pathsp :: ");
		print_listsp(jam->path);
	}
	return (1);
}
