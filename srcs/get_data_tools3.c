/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_tools3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 02:45:21 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/31 14:10:34 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

int			aux_treat_line(t_lemin *lemin, char *str)
{
	if (lemin->data_type == ROOMS)
	{
		if (get_rooms(lemin, str) < 0)
			return (-3);
	}
	if (lemin->data_type == TUBES)
	{
		if (get_tubes(lemin, str) < 0)
			return (-3);
	}
	return (0);
}

t_nod		*aux_if_match(t_list *tmp, char *str, int *len, int nod)
{
	while (tmp)
	{
		*len = ft_dashstrlen(str);
		if (nod)
		{
			if (!ft_strncmp(tmp->nod->name, str, *len))
				return (tmp->nod);
		}
		else
		{
			if (!ft_strcmp(tmp->nod->name, str))
				return (tmp->nod);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int			aux_treat_line2(t_lemin *lemin, char *str)
{
	if (*(str + 1) == '#')
	{
		if (!ft_strcmp(str + 2, "end") && lemin->props == -1)
			lemin->props = END;
		else if (!ft_strcmp(str + 2, "start") && lemin->props == -1)
			lemin->props = START;
		else
			return (-2);
	}
	else
		return (-2);
	return (0);
}

int			aux_get_data(char *str, t_lemin *lemin)
{
	int		ret2;
	char	*tmp;

	ret2 = 0;
	tmp = ft_strsub(str, 0, ft_strlen(str));
	if ((ret2 = treat_line(lemin, str)) == -1)
	{
		if (tmp)
			free(tmp);
		return (0);
	}
	if (ret2 == -3)
	{
		if (tmp)
			free(tmp);
		return (-1);
	}
	if (ret2 != -2)
		ft_putendl(tmp);
	if (tmp)
		free(tmp);
	return (0);
}
