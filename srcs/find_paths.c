/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:46:05 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/26 17:43:00 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "check_errors.h"
#include "debug.h"

void	print_listsp(t_listsp *listsp)
{
	if (!listsp)
		error("listsp set to NULL");
	while (listsp)
	{
		print_list(listsp->list);
		print_type("listsp->path_len", &(listsp->path_len), INT);
		listsp = listsp->next;
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

static t_jam	*init_and_get_jam(t_lemin *lemin, t_list *links)
{
	t_jam	*tmp;

	tmp = NULL;
	if (!lemin)
		check_errors(NUL, __FILE__, "lemin");
	if (!lemin->jam)
	{
		lemin->jam = (t_jam*)malloc(sizeof(t_jam));
		if (!lemin->jam)
			check_errors(NUL, __FILE__, "lemin->jam");
		lemin->jam->nod = links->nod;
		lemin->jam->pathsp = NULL;
		lemin->jam->next = NULL;
		return (lemin->jam);
	}
	else
	{
		tmp = lemin->jam;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next =(t_jam*)malloc(sizeof(t_jam));
		if (!tmp->next)
			check_errors(NUL, __FILE__, "tmp");
		tmp = tmp->next;
		tmp->next = NULL;
		tmp->pathsp = NULL;
		tmp->nod = links->nod;
		return (tmp);
	}
	return (NULL);
}

static void	remove_jam(t_lemin *lmin, t_jam *jam, t_jam *prec)
{
	if (!lmin)
		check_errors(NUL, __FILE__, "lmin");
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

void	get_paths(t_lemin *lemin)
{
	t_list		*links;
//	t_listsp	*listsp;
//	t_listsp	*tmp;
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
		printf("nod = [%s]\n", links->nod->name);/*_DEBUG_*/
//		if (lemin->path)
//		{
////			tmp = lemin->pathsp;
////			listsp = new_listsp(lemin->path, lemin->path_len, lemin->path_nbr);
//			if (!lemin->pathsp)
//			{
//				lemin->pathsp = listsp; 
//				lemin->pathsp->next = NULL;
//			}
//			else
//			{
//				while (tmp->next)
//					tmp = tmp->next;
//				tmp->next = listsp;
//			}
//			lemin->path_nbr++;
//		}
//		debug_nod(links->nod);
		if (!jam->pathsp)
			remove_jam(lemin, jam, j_prec);
		else
			j_prec = jam;
//		print_jams(jam);/*_DEBUG_*/
		links->nod->bool = FALSE;
		links = links->next;
	}
}
