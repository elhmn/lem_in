/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 07:04:24 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/30 16:57:08 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

int		hashtab_chr(t_list **hashtab, void *data)
{
	char		*str;
	t_nod		*nod1;
	t_nod		*nod2;
	int			len;

	str = (char*)data;
	if (str && hashtab)
	{
		if ((nod1 = if_match(str, hashtab, 1)))
		{
			len = ft_strlen(nod1->name);
			if (str[len - 1] == '-')
				return (0);
			if ((nod2 = if_match(str + len + 1, hashtab, 0)))
			{
				add_link(nod1, nod2);
				return (1);
			}
		}
	}
	return (0);
}

int		is_tube(char *str, t_lemin *lemin)
{
	if (str && lemin)
	{
		if (hashtab_chr(lemin->hashtab, str))
			return (1);
	}
	return (0);
}

int		is_room(char *str, t_lemin *lemin)
{
	char	*tmp1;

	tmp1 = str;
	while (*str)
		str++;
	str--;
	while (str != tmp1 && ft_isdigit(*str))
		str--;
	if (*str == ' ' && ft_isdigit(*(str - 1)))
		str--;
	else
		return (0);
	while (str != tmp1 && ft_isdigit(*str))
		str--;
	if (*str == ' ')
	{
		lemin->end_name = str;
		str--;
	}
	else
		return (0);
	if (*tmp1 == 'L')
		error();
	return (1);
}

void	hashtab_addelem(t_lemin *lemin, t_nod *nod)
{
	t_list		*elem;
	t_list		*tmp;
	t_ulong		hash;
	int			i;

	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		error();
	elem->nod = nod;
	elem->next = NULL;
	hash = hash3(nod->name);
	if (!lemin->hashtab[hash])
		lemin->hashtab[hash] = elem;
	else
	{
		tmp = lemin->hashtab[hash];
		while (tmp->next)
		{
			if (!(i = ft_strcmp(tmp->nod->name, nod->name)))
				break ;
			tmp = tmp->next;
		}
		i = ft_strcmp(tmp->nod->name, nod->name);
		if (i)
			tmp->next = elem;
	}
}

void	get_room_data(char *str, t_lemin *lemin)
{
	t_nod	*nod;
	char	*tmp;
	char	*car_x;
	char	*car_y;

	nod = NULL;
	tmp = str;
	if (!(nod = (t_nod*)malloc(sizeof(t_nod))))
		error();
	tmp[lemin->end_name - tmp] = '\0';
	nod->name = tmp;
	car_x = ft_strchr(lemin->end_name + 1, ' ');
	*car_x = '\0';
	nod->coord.x = ft_atoi(lemin->end_name + 1);
	car_y = ft_strchr(car_x + 1, '\0');
	*car_y = '\0';
	nod->coord.y = ft_atoi(car_x + 1);
	nod->links = NULL;
	nod->bool = 0;
	nod->index = lemin->room_nbr;
	get_props(lemin, nod);
	lemin->room_nbr++;
	hashtab_addelem(lemin, nod);
}
