/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 06:39:48 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/31 12:30:03 by bmbarga          ###   ########.fr       */
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
	while (list && list->nod != end)
	{
		list->nod->bool = TRUE;
		list = list->next;
	}
}

void			reset_nod_state(t_list *list, t_nod *end)
{
	while (list && list->nod != end)
	{
		list->nod->bool = FALSE;
		list = list->next;
	}
}

int				correct_path(t_lemin *lemin, t_jam *jam)
{
	t_list		*tmp;
	t_listsp	*tmpsp;
	t_jam		*jam;
	int		len;

	len = -1;
	jam = NULL;
	if (lemin && jam)
	{
		if (!(jam = get_jam_to_change(jam, lemin->room_nbr)))
			return (0); // no path to modify
		tmpsp = jam[i].path;
		//change the longer path
		while (tmpsp)
		{
			set_nod_state(tmpsp);
			pathfinder(jam[i], lemin);
			tmpsp = tmpsp->next;
		}
	}
	return (1);
}
