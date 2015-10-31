/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 12:57:34 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/30 02:44:22 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

void		print_listsp(t_listsp *listsp)
{
	if (!listsp)
		error();
	while (listsp)
	{
		print_list(listsp->list);
		print_type("listsp->path_len", &(listsp->path_len), INT);
		print_type("listsp->a", &(listsp->a), INT);
		listsp = listsp->next;
	}
}

void		print_list_nod(t_list *list)
{
	while (list)
	{
		ft_putendl("elem ::");
		debug_nod(list->nod);
		list = list->next;
	}
}

void		print_firstsp(t_listsp *sp)
{
	if (!sp)
		error();
	print_list(sp->list);
	print_type("sp->path_len", &(sp->path_len), INT);
	print_type("sp->a", &(sp->a), INT);
}

void		print_jams(t_jam *jam)
{
	t_jam	*tmp;
	int		i;

	i = 0;
	tmp = jam;
	if (!tmp)
		error();
	while (tmp)
	{
		if (tmp)
		{
			ft_putstr("JAM [");
			ft_putnbr(i);
			ft_putendl("] :: ");
			if (tmp->nod)
			{
				print_type("jam->nod->name", tmp->nod->name, CHAR);
				print_type("jam->nod->index", &(tmp->nod->index), INT);
			}
			print_listsp(tmp->pathsp);
		}
		tmp = tmp->next;
		i++;
		ft_putstr("---------------------------------------\n\n\n");
	}
}

void		print_jam(t_jam *jam, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		ft_putstr("---------------------------------------\n");
		if ((jam + i) && jam[i].nod)
		{
			ft_putstr("JAM [");
			ft_putnbr(i);
			ft_putendl("] :: ");
			print_type("jam->nod->name", jam[i].nod->name, CHAR);
			print_type("jam->nod->index", &(jam[i].nod->index), INT);
			print_listsp(jam[i].pathsp);
		}
		ft_putstr("---------------------------------------\n\n\n");
	}
}
