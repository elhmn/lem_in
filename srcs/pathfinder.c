/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 10:25:16 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/27 16:05:05 by bmbarga          ###   ########.fr       */
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

t_list	*pathfinder(t_nod *nod, t_lemin *lemin)
{
	t_list	*tmp;

	tmp = nod->links;
	if (tmp) //end
		return (NULL);
	while (tmp)
	{
		pathfinder(tmp->nod, lemin);	
		tmp = tmp->next;
	}









	/*
	if (nod == lemin->end || !tmp || is_full(tmp)) //end of map or graph
	{
		ft_putendl("");
//		print_type("tmp->nod->name", tmp->nod->name, CHAR);
//		debug_nod(tmp->nod);
		return (tmp);
	}
//	ft_putstr(nod->name);
//	ft_putstr(" ==> \n[\n");
	while (tmp)
	{
		if (!tmp->nod->bool)
		{
			ft_putstr(tmp->nod->name);
//			ft_putstr(" || ");
//			if (tmp->next)
//				ft_putstr(tmp->next->nod->name);
			ft_putstr(" :: ");
//			print_type("tmp->nod->name", tmp->nod->name, CHAR);
//			debug_nod(tmp->nod);
			tmp->nod->bool = 1;
			pathfinder(tmp->nod, lemin);
			tmp->nod->bool = 0;
		}
		tmp = tmp->next;
	}
	ft_putendl("]");
	*/
	return (NULL);
}
