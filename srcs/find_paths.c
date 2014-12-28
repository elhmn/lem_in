/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:46:05 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/28 19:16:21 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
static void	listsp_addelem(t_listsp *begin, t_list *listsp2)
{
	if (!begin)
	{
		begin = listsp2;
	}
	if (begin)
	{
		while (begin->next)
			listsp = listsp->next;
		listsp->next = list;
	}
}
*/

void	print_listsp(t_listsp *listsp)
{
	if (!listsp)
		ft_putendl("list set to NULL");
	while (listsp)
	{
		print_list(listsp->list);
		listsp = listsp->next;
	}
}

void	get_paths(t_lemin *lemin)
{
	t_list		*links;
	t_listsp	*listsp;
	t_listsp	*tmp;

	links = lemin->start->links;
	listsp = NULL;
	while (links)
	{
		ft_putstr("lien :: ");
		ft_putendl(links->nod->name);
		if (!(listsp = (t_listsp*)malloc(sizeof(t_listsp))))
			error("");
		tmp = lemin->pathsp;
		lemin->chemin = NULL;
		lemin->path = NULL;
		pathfinder(lemin->start, lemin);
		print_list(lemin->path);
		pathfinder(links->nod, lemin);
		print_list(lemin->path);
		if (links->next)
		{
			ft_putstr("TEST BIG \n");
			pathfinder(links->next->nod, lemin);
		}
		print_list(lemin->path);
		listsp->list = lemin->path;
		listsp->next = NULL;
		if (!lemin->pathsp)
		{
			lemin->pathsp = listsp; 
			lemin->pathsp->next = NULL;
		}
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = listsp;
		}
		links = links->next;
	}
}
