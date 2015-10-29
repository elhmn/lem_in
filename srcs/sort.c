/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 20:01:21 by mnguyen           #+#    #+#             */
/*   Updated: 2015/10/29 17:46:10 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			list_len(t_listsp *pathsp)
{
	int i;

	i = 0;
	while (pathsp)
	{
		i++;
		pathsp = pathsp->next;
	}
	return (i);
}

void		sort(t_listsp **pathsp)
{
	int			len;
	int			i;
	t_listsp	*p;
	t_listsp	*last;

	len = list_len(*pathsp);
	while (len > 1)
	{
		i = 1;
		p = *pathsp;
		last = NULL;
		while (i < len)
		{
			if (p->path_len > p->next->path_len)
				p = swap(last, p, p->next, &*pathsp);
			last = p;
			p = p->next;
			i++;
		}
		len--;
	}
}

t_listsp	*swap(t_listsp *last, t_listsp *s1, t_listsp *s2, t_listsp **pathsp)
{
	if (last)
	{
		last->next = s2;
		s1->next = s2->next;
		s2->next = s1;
		return (s2);
	}
	else
	{
		s1->next = s2->next;
		s2->next = s1;
		return (*pathsp = s2);
	}
}
