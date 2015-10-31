/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 20:23:53 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/30 17:07:07 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

/*
** les noeuds seront stocker dans une table de hash (hotrace)
*/

int		get_ants(t_lemin *lemin, char *str)
{
	if (!is_number(str))
		return (-1);
	lemin->ant_nbr = ft_atoi(str);
	lemin->data_type = ROOMS;
	return (0);
}

int		get_rooms(t_lemin *lemin, char *str)
{
	if (!is_room(str, lemin))
	{
		if (!lemin->room_nbr)
			return (-1);
		lemin->data_type = TUBES;
	}
	if (lemin->data_type == ROOMS)
		get_room_data(str, lemin);
	return (0);
}

int		get_tubes(t_lemin *lemin, char *str)
{
	if (lemin && str && !is_tube(str, lemin))
		return (-1);
	lemin->data_type = TUBES;
	return (0);
}

int		treat_line(t_lemin *lemin, char *str)
{
	if (!lemin)
		error();
	if (str && *str == '\0')
		return (-1);
	if (*str == '#')
	{
		if (aux_treat_line2(lemin, str) == -2)
			return (-2);
	}
	else if (lemin->data_type == ANTS_NBR)
	{
			if (get_ants(lemin, str) < 0)
				return (-3);
	}
	else
		if (aux_treat_line(lemin, str) == -3)
			return (-3);
	return (0);
}

int		get_data(t_lemin *lemin)
{
	char	*str;
	int		ret;

	str = NULL;
	while ((ret = get_next_line(0, &str)) && ret != -1)
	{
		if (aux_get_data(str, lemin) == -1)
			return (0);
	}
	if (ret == -1)
		error();
	return (0);
}
