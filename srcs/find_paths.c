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

void	get_paths(t_lemin *lemin)
{
	t_list		*links;
	t_listsp	*listsp;
	t_listsp	*tmp;

	links = lemin->start->links;
	listsp = NULL;
	while (links)
	{
		lemin->chemin = NULL;
		lemin->path = NULL;
		lemin->path_len = 0;
		lemin->len_tmp = 0;
		pathfinder(links->nod, lemin);
		if (lemin->path)
		{
			if (!(listsp = (t_listsp*)malloc(sizeof(t_listsp))))
				error("");
			tmp = lemin->pathsp;
			listsp->list = lemin->path;
			listsp->path_len = lemin->path_len;
			listsp->next = NULL;
			listsp->index = lemin->path_nbr;
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
