/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 15:59:30 by mnguyen           #+#    #+#             */
/*   Updated: 2015/10/28 16:20:31 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		calc(t_listsp *pathsp, int a_t)
{
	t_struct c;

	calc_f1(pathsp, &c);
	calc_a(pathsp, &c, a_t);
	if (c.f_t < a_t)
		add(pathsp, (a_t - c.f_t));
	return (pathsp->path_len + pathsp->a - 1);
}

void	calc_f1(t_listsp *pathsp, t_struct *c)
{
	t_listsp *p;

	p = pathsp;
	c->s_t = 0;
	c->n = 1;
	p = p->next;
	while (p)
	{
		c->s_t += p->path_len;
		c->n++;
		p = p->next;
	}
}

void	calc_a(t_listsp *pathsp, t_struct *c, int a_t)
{
	t_listsp	*p;
	int			s;
	int			i;

	i = 2;
	s = 0;
	pathsp->a = (a_t - (c->n - 1) * pathsp->path_len + c->s_t) / c->n;
	c->f_t = pathsp->a;
	p = pathsp->next;
	while (i <= c->n)
	{
		if ((p->a = pathsp->path_len + pathsp->a - p->path_len) <= 0)
		{
			c->s_t = s;
			c->n = i - 1;
			sous(p);
			calc_a(pathsp, c, a_t);
			break ;
		}
		c->f_t += p->a;
		s += p->path_len;
		p = p->next;
		i++;
	}
}

void	add(t_listsp *pathsp, int i)
{
	t_listsp *p;

	p = pathsp;
	while (i > 0)
	{
		p->a += 1;
		p = p->next;
		i--;
	}
}

void	sous(t_listsp *pathsp)
{
	while (pathsp)
	{
		pathsp->a = 0;
		pathsp = pathsp->next;
	}
}
