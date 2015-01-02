/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 10:25:16 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/02 17:32:18 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

static int		is_full(t_list *links)
{
	while (links)
	{
		if (!links->nod->bool)
			return (0);
		links = links->next;
	}
	return (1);
}


static void		add_path(t_nod *nod, t_lemin *lemin)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp2 = lemin->chemin;
	tmp = (t_list*)malloc(sizeof(t_list));
	if (nod)
	{
		if (!tmp)
			error("");
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

static void		remove_path(t_lemin *lemin)
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

void			print_list(t_list *list)
{
	ft_putendl("LIST :: \n\tSTART\n");
	if (list)
	{
		ft_putstr("\t\t[");
		while (list)
		{
			ft_putstr(list->nod->name);
			if (list->next)
				ft_putstr("] +--> [");
			list = list->next;
		}
		ft_putendl("]");
	}
	ft_putendl("\tEND\n");
}

static t_list	*make_cpy(t_list *list2)
{
	t_list	*tmp;
	t_list	*list1;
	t_list	*end;

	tmp = NULL;
	if (list2)
	{	
		tmp = (t_list*)malloc(sizeof(t_list));
		if (!tmp)
			error("");
		tmp->nod = list2->nod;
		tmp->next = NULL;
		list1 = tmp;
		end = list1;
		list2 = list2->next;
		while (list2)
		{
			tmp = (t_list*)malloc(sizeof(t_list));
			if (!tmp)
				error("");
			tmp->nod = list2->nod;
			tmp->next = NULL;
			list1->next = tmp;
			list2 = list2->next;
			list1 = list1->next;
		}
	}
	return (end);
}

t_nod	*pathfinder(t_nod *nod, t_lemin *lemin)
{
	t_list	*links;

	links = nod->links;
	add_path(nod, lemin);
	if (nod == lemin->end || is_full(links))
	{
		if (nod == lemin->end)
		{
//			ft_putendl("lemin->chemin :: ");
//			print_list(lemin->chemin);
			if (lemin->path_len > lemin->len_tmp || !lemin->path_len)
			{
				lemin->path_len = lemin->len_tmp;
				lemin->path = make_cpy(lemin->chemin);
			}
		}
		remove_path(lemin);
		return (NULL);
	}
	lemin->len_tmp++;
	while (links)
	{
//		print_type("links->nod->bool", &(links->nod->bool), INT);
		if (!links->nod->bool)
		{
			links->nod->bool = TRUE;
			pathfinder(links->nod, lemin);
			links->nod->bool = FALSE;
		}
		links = links->next;
	}
	lemin->len_tmp--;
	remove_path(lemin);
	return (NULL);
}
