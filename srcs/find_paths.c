/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:46:05 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/31 15:45:12 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

void	print_listsp(t_listsp *listsp)
{
	if (!listsp)
		ft_putendl("list set to NULL");
	while (listsp)
	{
		print_list(listsp->list);
		print_type("listsp->path_len", &(listsp->path_len), INT);
		listsp = listsp->next;
	}
}

void	set_nod_state(t_list *list, int bool, int nbr)
{
	int		i;

	i = -1;
	while (++i < nbr && list)
	{
		list->nod->bool = bool;
		list = list->next;
	}
}

t_listsp	*new_listsp(t_list *path, int path_len, int index)
{
	t_listsp	*listsp;

	listsp = NULL;
	if (!(listsp = (t_listsp*)malloc(sizeof(t_listsp))))
		error("");
	listsp->list = path;
	listsp->path_len = path_len;
	listsp->next = NULL;
	listsp->index = index;
	return (listsp);
}

void		reset_data(t_lemin *lemin)
{
	lemin->chemin = NULL;
	lemin->path = NULL;
	lemin->path_len = 0;
	lemin->len_tmp = 0;
}

void	get_paths(t_lemin *lemin)
{
	t_list		*links;
	t_listsp	*listsp;
	t_listsp	*tmp;

	links = lemin->start->links;
	while (links)
	{
		reset_data(lemin);
		pathfinder(links->nod, lemin);
		if (lemin->path)
		{
			tmp = lemin->pathsp;
			listsp = new_listsp(lemin->path, lemin->path_len, lemin->path_nbr);
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
			lemin->path_nbr++;
		}
		links = links->next;
	}
}
