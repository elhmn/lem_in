/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 18:22:15 by mnguyen           #+#    #+#             */
/*   Updated: 2015/10/29 16:54:37 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** check_comb return 1 if comb valide 0 sinon 
*/

int		check_comb(t_jam *comb)
{
	t_listsp	*sp_tmp;

	if (!comb)
		check_errors(NUL, __FILE__, "comb");
	sp_tmp = comb->pathsp;
	while (sp_tmp->next)
	{
		sp_tmp = sp_tmp->next;
	};
	return (0);
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
