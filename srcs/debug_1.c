/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 07:04:19 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/27 07:06:15 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

void	print_type(char *str, void *data, int type)
{
	int		*t_int;
	char	*t_char;

	t_int = (int*)data;
	t_char = (char*)data;
	ft_putstr("\t");
	ft_putstr(str);
	ft_putstr(" = [");
	if (type == INT)
		ft_putnbr(*t_int);
	else if (type == CHAR)
		ft_putstr(t_char);
	ft_putendl("]");
}

void	debug_links(t_nod *nod)
{
	t_list	*tmp;

	if (nod && nod->links)
	{
		tmp = nod->links;
		while (tmp)
		{
			print_type("tmp->nod->name", tmp->nod->name, CHAR);
			tmp = tmp->next;
		}
	}
}

void	print_hashtab(t_list **hashtab)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (hashtab)
	{
		while (i < MOD_SIZE)
		{
			if (hashtab[i])
			{
				ft_putstr("hashtab[");
				ft_putnbr(i);
				ft_putstr("] :: \n");
				tmp = hashtab[i];
				while (tmp)
				{
					debug_nod(tmp->nod);
					tmp = tmp->next;
				}
			}
			i++;
		}
	}
}

void	debug_lemin(t_lemin *lemin)
{
	if (!lemin)
		error(" :: print lemin");
	ft_putendl(" DEBUG LEMIN :: ");
	print_type("lemin->ant_nbr", &(lemin->ant_nbr), INT);
	print_type("lemin->data_type", &(lemin->data_type), INT);
	print_type("lemin->room_nbr", &(lemin->room_nbr), INT);
	print_type("lemin->data_type", &(lemin->data_type), INT);
	print_type("lemin->props", &(lemin->props), INT);
	ft_putendl("lemin->start :: ");
	debug_nod(lemin->start);
	ft_putendl("lemin->end :: ");
	debug_nod(lemin->end);
	ft_putendl("");
	print_hashtab(lemin->hashtab);
}

void	debug_nod(t_nod *nod)
{
	int	ret;

	if (!nod)
		error(" :: print node");
	ft_putendl(" DEBUG NODE :: ");
	print_type("nod->name", nod->name, CHAR);
	print_type("nod->coord.x", &(nod->coord.x), INT);
	print_type("nod->coord.y", &(nod->coord.y), INT);
	print_type("nod->props", &(nod->props), INT);
	ret = hash3(nod->name);
	print_type("hash3(nod->name)", &ret, INT);
	ft_putendl("\tDEBUG LINKS ::");
	debug_links(nod);
	ft_putendl("");
}
