/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 16:26:06 by mnguyen           #+#    #+#             */
/*   Updated: 2015/10/28 16:29:35 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	aff_moove(int f, char *s, int *bool)
{
	if (!(*bool))
		write(1, " ", 1);
	else
		*bool = 0;
	write(1, "L", 1);
	ft_putnbr(f);
	write(1, "-", 1);
	ft_putstr(s);
}

void	aff_path(t_list *path, int a, int b, int *bool)
{
	int f;

	f = 0;
	if (b > 0)
		f = a;
	if (path->next)
		aff_path(path->next, path->nod->index, 1, bool);
	path->nod->index = f;
	if (f)
		aff_moove(f, path->nod->name, bool);
}

void	aff_line(t_listsp *pathsp, int *a)
{
	int bool;

	bool = 1;
	while (pathsp)
	{
		if (pathsp->path_len + pathsp->a > 0)
		{
			aff_path(pathsp->list, *a, pathsp->a, &bool);
			if (pathsp->a > 0)
				*a += 1;
			pathsp->a -= 1;
		}
		pathsp = pathsp->next;
	}
	write(1, "\n", 1);
}

void	set_index(t_listsp *pathsp)
{
	t_list *p;

	while (pathsp)
	{
		p = pathsp->list;
		while (p)
		{
			p->nod->index = 0;
			p = p->next;
		}
		pathsp = pathsp->next;
	}
}

void	aff(t_listsp *pathsp, int t_a)
{
	int a;
	int t;

	t = 1;
	set_index(pathsp);
	a = 1;
	while (t <= t_a)
	{
		aff_line(pathsp, &a);
		t++;
	}
}
