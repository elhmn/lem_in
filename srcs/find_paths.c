/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:46:05 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/30 11:53:11 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "check_errors.h"
#include "debug.h"

t_listsp		*new_listsp(t_list *path, int path_len, int index)
{
	t_listsp	*listsp;

	listsp = NULL;
	if (!(listsp = (t_listsp*)malloc(sizeof(t_listsp))))
		error();
	listsp->list = path;
	listsp->path_len = path_len;
	listsp->next = NULL;
	listsp->index = index;
	return (listsp);
}

void			reset_data(t_lemin *lemin)
{
	lemin->chemin = NULL;
	lemin->path = NULL;
	lemin->path_len = 0;
	lemin->len_tmp = 0;
}

static t_jam	*init_and_get_jam(t_lemin *lemin, t_list *links)
{
	t_jam	*tmp;

	tmp = NULL;
	if (!lemin)
		error();
	if (!lemin->jam)
	{
		if (!(lemin->jam = (t_jam*)malloc(sizeof(t_jam))))
			error();
		lemin->jam->nod = links->nod;
		tmp = lemin->jam;
	}
	else
	{
		tmp = lemin->jam;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_jam*)malloc(sizeof(t_jam))))
			error();
		tmp = tmp->next;
		tmp->nod = links->nod;
	}
	tmp->next = NULL;
	tmp->pathsp = NULL;
	return (tmp);
}

static void		remove_jam(t_lemin *lmin, t_jam *jam, t_jam *prec)
{
	if (!lmin)
		error();
	if (!prec)
	{
		if (jam)
			free(jam);
		lmin->jam = NULL;
	}
	else
	{
		if (jam)
			free(jam);
		prec->next = NULL;
	}
}

void			get_paths(t_lemin *lemin)
{
	t_list		*links;
	t_jam		*jam;
	t_jam		*j_prec;

	links = lemin->start->links;
	j_prec = NULL;
	while (links)
	{
		links->nod->bool = TRUE;
		reset_data(lemin);
		jam = init_and_get_jam(lemin, links);
		if (jam)
			pathfinder(links->nod, lemin, jam);
		if (!jam->pathsp)
			remove_jam(lemin, jam, j_prec);
		else
			j_prec = jam;
		links->nod->bool = FALSE;
		links = links->next;
	}
}
