/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_path_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 11:31:16 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/02 20:33:17 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

void			add_new_path(t_list **path, t_nod *start, t_lemin *lemin)
{
	t_list		*tmp;

	tmp = *path;
	if (lemin && path)
	{
		if (tmp->nod == start)
		{
			//free *path
			*path = lemin->path;
		}
		else
		{
			while (tmp->next && tmp->next->nod != start)
				tmp = tmp->next;
			if (tmp->next && tmp->next->nod == start )
			{
				//free path->next
				tmp->next = lemin->path;
			}
			else
				tmp->next = lemin->path;
		}
	}
}

void			set_nod_state(t_list *list, t_nod *end)
{
	if (list && end)
	{
		while (list && list->nod != end)
		{
			list->nod->bool = TRUE;
			list = list->next;
		}
		if (list->nod == end)
			list->nod->bool = TRUE;
	}
}

void			reset_nod_state(t_list *list, t_nod *end)
{
	while (list && list->nod != end)
	{
		list->nod->bool = FALSE;
		list = list->next;
	}
	if (list->nod == end)
		list->nod->bool = FALSE;
}

void			swap_listsp(t_listsp *list1, t_listsp *list2)
{
	t_list	*tmp;
	int		tmp_len;

	if (list1 && list2)
	{
		tmp = list1->list;
		tmp_len = list1->path_len;
		list1->list = list2->list;
		list1->path_len = list2->path_len;
		list2->list = tmp;
		list2->path_len = tmp_len;
	}
}

void			sort_listsp(t_listsp *listsp)
{
	t_listsp *tmp1;
	t_listsp *tmp2;

	tmp1 = listsp;
	if (listsp)
	{
		while (tmp1->next)
		{
			tmp2 = tmp1->next;
			while (tmp2)
			{
				if (tmp1->path_len > tmp2->path_len)
					swap_listsp(tmp1, tmp2);
				tmp2 = tmp2->next;
			}
			tmp1 = tmp1->next;
		}
	}
}
