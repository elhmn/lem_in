/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 10:25:16 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/28 13:56:36 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

int		is_full(t_list *links)
{
	while (links)
	{
		if (!links->nod->bool)
			return (0);
		links = links->next;	
	}
	return (1);
}

t_list	*pathfinder(t_nod *nod, t_lemin *lemin, t_nod *parent)
{
	t_list	*links;

	links = nod->links;
	if (nod == lemin->end || is_full(links)) //end of map or graph
	{
		if (nod == lemin->end)
		{
			if (lemin->path_len > lemin->len_tmp || !lemin->path_len)
				lemin->path_len = lemin->len_tmp;
			parent = parent;
			ft_putstr(parent->name);
			ft_putstr(" :: ");
			ft_putendl(nod->name);
			ft_putendl("exit founded");
			print_type("lemin->len_tmp", &(lemin->len_tmp), INT);
		}
		if (is_full(links))
		{
//			ft_putstr(links->nod->name);
//			ft_putendl(" ==> is full");
		}
		return (links);
	}
	parent = parent;
	ft_putstr(parent->name);
	ft_putstr(" :: ");
	ft_putendl(nod->name);
	lemin->len_tmp++;
	while (links)
	{
		if (!links->nod->bool)
		{
			links->nod->bool = 1;
			pathfinder(links->nod, lemin, nod);
			links->nod->bool = 0;
		}
		links = links->next;
	}
	lemin->len_tmp--;
//	ft_putstr("\nfin de parcours des liens du noeuds :: ");
//	ft_putendl(nod->name);
	return (NULL);
}
