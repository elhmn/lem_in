/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 06:39:48 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/01 12:32:52 by bmbarga          ###   ########.fr       */
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

	tmp = NULL;
	if (list && nod)
	{
		while (list && list->nod != nod)
		{
			tmp = list->nod;
			list = list->next;
		}
		if (list->nod == nod)
			return (tmp);
	}
	return (NULL);
}

void			modify_path(t_jam *jam, t_listsp *tmpsp, t_lemin *lemin)
{
	set_nod_state(tmpsp->list, jam->nod);
	get_start_nod(tmpsp->list, jam->nod);
	reset_data(lemin); // for pathfinder
	pathfinder(jam->nod, lemin);
	if (lemin->path)
	{
		tmpsp->path_len = tmpsp->path_len + lemin->path_len;
	}
}

//modifier la longueur du bordel

int				correct_path(t_lemin *lemin, t_jam *jam)
{
	t_listsp	*tmpsp;

	if (lemin && jam)
	{
		if (!(jam = get_jam_to_change(jam, lemin->room_nbr)))
			return (0); // no path to modify
/*
		ft_putendl("JAM");
		print_type("jam->nod->name", jam->nod->name, CHAR);
		print_type("jam->nod->index", &(jam->nod->index), INT);
		print_listsp(jam->path);
*/
		print_listsp(jam->path);/**********************/
		sort_listsp(jam->path);//classer le tableau en fonction de la longueur des chemins
		ft_putendl("\n\n\n\n\n");/**********************/
		ft_putendl("after sorted ::\n");/**********************/
		print_listsp(jam->path);/**********************/
		tmpsp = jam->path->next;
		ft_putendl("The path to change ::\n");/**********************/
		print_listsp(tmpsp);/**********************/
		while (tmpsp)
		{
			modify_path(jam, tmpsp, lemin);
			tmpsp = tmpsp->next;
		}
	}
	return (1);
}
