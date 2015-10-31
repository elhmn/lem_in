/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 03:32:02 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/30 03:34:08 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

int			is_full(t_list *links)
{
	while (links)
	{
		if (!links->nod->bool)
			return (0);
		links = links->next;
	}
	return (1);
}

void		add_path(t_nod *nod, t_lemin *lemin)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp2 = lemin->chemin;
	tmp = (t_list*)malloc(sizeof(t_list));
	if (nod)
	{
		if (!tmp)
			error();
		tmp->nod = nod;
		tmp->next = NULL;
		if (!tmp2)
			lemin->chemin = tmp;
		else
		{
			while (tmp2->next)
				tmp2 = tmp2->next;
			tmp2->next = tmp;
		}
	}
}

void		remove_path(t_lemin *lemin)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = lemin->chemin;
	tmp2 = tmp;
	if (tmp)
	{
		if (!tmp->next)
		{
			free(tmp);
			lemin->chemin = NULL;
		}
		if (tmp->next)
		{
			while (tmp->next)
			{
				tmp2 = tmp;
				tmp = tmp->next;
			}
			free(tmp);
			tmp2->next = NULL;
		}
	}
}
