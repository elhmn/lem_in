/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_tools2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 07:04:30 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/27 14:00:08 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

t_nod		*if_match(char *str, t_list **hashtab)
{
	int		i;
	int		len;
	t_list	*tmp;

	len = 0;
	i = -1;
	if (hashtab)
	{
		while (++i < MOD_SIZE)
		{
			if (hashtab[i])
			{
				tmp = hashtab[i];
				while (tmp)
				{
					len = ft_strlen(tmp->nod->name);
					if (!ft_strncmp(tmp->nod->name, str, len))
						return (tmp->nod);
					tmp = tmp->next;
				}
			}
		}
	}
	return (NULL);
}

static void	nod_addaux(t_list *tmp, t_list *elem, t_nod *nod1, t_nod *nod2)
{
	int		i;

	tmp = nod1->links;
	while (tmp->next)
	{
		if (!(i = ft_strcmp(tmp->nod->name, nod2->name)))
			break ;
		tmp = tmp->next;
	}
	i = ft_strcmp(tmp->nod->name, nod2->name);
	if (i)
		tmp->next = elem;
}

void		nod_addelem(t_nod *nod1, t_nod *nod2)
{
	t_list	*tmp;
	t_list	*elem;

	tmp = NULL;
	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		error(" :: malloc elem");
	elem->nod = nod2;
	elem->next = NULL;
	if (!nod1->links)
	{
		nod1->links = elem;
		tmp = nod1->links;
	}
	else
		nod_addaux(tmp, elem, nod1, nod2);
}

void		add_link(t_nod *nod1, t_nod *nod2)
{
	if (nod1 && nod2)
	{
		nod_addelem(nod1, nod2);
		nod_addelem(nod2, nod1);
	}
	else
		error("");
}

void		get_props(t_lemin *lemin, t_nod *nod)
{
	nod->props = lemin->props;
	if (lemin->props != -1)
	{
		if (lemin->props == START && lemin->start)
			error(" :: cant get more than one start");
		if (lemin->props == END && lemin->end)
			error(" :: cant get more than one end");
		if (lemin->props == START)
			lemin->start = nod;
		if (lemin->props == END)
			lemin->end = nod;
		lemin->props = -1;
	}
}
