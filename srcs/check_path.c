/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 18:22:15 by mnguyen           #+#    #+#             */
/*   Updated: 2015/10/29 20:43:24 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_comb(t_listsp *pathsp)
{
	t_listsp *p1;
	t_listsp *p2;

/*	if (!pathsp)
		error;*/
	p1 = pathsp;
	while (p1->next)
	{
		p2 = p1->next;
		while (p2)
		{
			if (!check_path(p1, p2))
				return (0);
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return (1);
}

int		check_path(t_listsp *p1, t_listsp *p2)
{
	t_list		*l1;
	t_list		*l2;

/*	if (!p1 || !p2 || !p1->list || !p2->list)
		error;
*/
	l1 = p1->list;
	while (l1->next)
	{
		l2 = p2->list;
		while (l2->next)
		{
			if (!ft_strcmp(l1->nod->name, l2->nod->name))
				return (0);
			l2 = l2->next;
		}
		l1 = l1->next;
	}
	return (1);
}
