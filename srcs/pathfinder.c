/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 10:25:16 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/30 03:43:39 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

static void		aux_make_cpy(t_list **tmp, t_nod *nod)
{
	if (!(*tmp = (t_list*)malloc(sizeof(t_list))))
		error("");
	(*tmp)->nod = nod;
	(*tmp)->next = NULL;
}

static t_list	*make_cpy(t_list *list2)
{
	t_list	*tmp;
	t_list	*list1;
	t_list	*end;

	end = NULL;
	tmp = NULL;
	if (list2)
	{
		aux_make_cpy(&tmp, list2->nod);
		list1 = tmp;
		end = list1;
		list2 = list2->next;
		while (list2)
		{
			aux_make_cpy(&tmp, list2->nod);
			tmp->next = NULL;
			list1->next = tmp;
			list2 = list2->next;
			list1 = list1->next;
		}
	}
	return (end);
}

static void		put_path(t_lemin *lemin, t_jam *jam)
{
	t_listsp	*tmp;

	tmp = NULL;
	if (!jam)
		check_errors(NUL, __FILE__, "jam");
	if (!jam->pathsp)
	{
		if (!(jam->pathsp = (t_listsp*)malloc(sizeof(t_listsp))))
			check_errors(MALLOC, __FILE__, "jam->path");
		jam->pathsp->next = NULL;
		tmp = jam->pathsp;
	}
	else
	{
		tmp = jam->pathsp;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_listsp*)malloc(sizeof(t_listsp))))
			check_errors(MALLOC, __FILE__, "tmp->path");
		tmp = tmp->next;
		tmp->next = NULL;
	}
	tmp->path_len = lemin->len_tmp + 1;
	tmp->list = make_cpy(lemin->chemin);
	tmp->a = 0;
}

t_nod			*pathfinder(t_nod *nod, t_lemin *lemin, t_jam *jam)
{
	t_list	*links;

	links = nod->links;
	add_path(nod, lemin);
	if (nod == lemin->end || is_full(links))
	{
		if (nod == lemin->end)
			put_path(lemin, jam);
		remove_path(lemin);
		return (NULL);
	}
	lemin->len_tmp++;
	while (links)
	{
		if (!links->nod->bool)
		{
			links->nod->bool = TRUE;
			pathfinder(links->nod, lemin, jam);
			links->nod->bool = FALSE;
		}
		links = links->next;
	}
	lemin->len_tmp--;
	remove_path(lemin);
	return (NULL);
}
