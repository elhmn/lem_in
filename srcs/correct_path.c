/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 06:39:48 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/31 16:21:14 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

static t_jam	*get_jam_to_change(t_jam *jam, int size)
{
	int		i;

	i = -1;
	while (i++ < size)
	{
		if (jam[i].path)
			return (jam + i);
	}
	return (NULL); // no jam exist
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
		if (list == end)
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
	if (list == end)
		list->nod->bool = FALSE;
}

void			swap_listsp(t_listsp *list1, t_listsp *list2)
{
	t_list	*tmp;
	int		tmp_len;

	if (list1 && list2)
	{
		tmp = list1->list;
		len = list1->path_len;
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
				if (tmp1.path_len > tmp2.path_len)
					swap_listsp(tmp1, tmp2);
				tmp2 = tmp2->next;
			}
			tmp1 = tmp1->next;
		}
	}
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

void			add_path(t_list path)
{

}


void			modify_path(t_jam *jam, t_listsp *tmpsp, t_lemin *lemin)
{
	set_nod_state(tmpsp->list, jam->nod);
	get_start_nod(tmpsp->list, jam->nod);
	reset_data(lemin); // for pathfinder
	pathfinder(jam->nod, lemin);
	if (lemin->path)
	{
		tmpsp->pathlen = tmpsp->path_len + lemin->path_len;
	}
}

	//modifier la longueur du bordel
int				correct_path(t_lemin *lemin, t_jam *jam)
{
	t_list		*tmp;
	t_listsp	*tmpsp;
	t_jam		*jam;

	if (lemin && jam)
	{
		if (!(jam = get_jam_to_change(jam, lemin->room_nbr)))
			return (0); // no path to modify
		sort_listsp(jam[i].path); //classer le tableau en fonction de la longueur des chemins
		tmpsp = jam[i].path->next;
		while (tmpsp)
		{
			modify_path(jam + i, tmpsp, lemin);
			tmpsp = tmpsp->next;
		}
	}
	return (1);
}
