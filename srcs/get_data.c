/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 20:23:53 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/27 07:07:11 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

/*
** les noeuds seront stocker dans une table de hash (hotrace)
*/

void	get_ants(t_lemin *lemin, char *str)
{
	if (!is_number(str))
		error(" :: str isnt number");
	lemin->ant_nbr = ft_atoi(str);
	lemin->data_type = ROOMS;
}

void	get_rooms(t_lemin *lemin, char *str)
{
	lemin = lemin;
	if (!is_room(str, lemin))
	{
		if (!lemin->room_nbr)
			error("no rooms");
		lemin->data_type = TUBES;
	}
	if (lemin->data_type == ROOMS)
		get_room_data(str, lemin);
}

void	get_tubes(t_lemin *lemin, char *str)
{
	if (lemin && str && !is_tube(str, lemin))
	{
		ft_putendl(str);
		error(" :: is not a tube");
	}
	lemin->data_type = TUBES;
}

void	treat_line(t_lemin *lemin, char *str)
{
	if (!lemin)
		error(" :: lemin");
	if (str && *str == '\0')
		error(" :: ligne vide || str set to NULL");
	if (*str == '#')
	{
		if (*(str + 1) == '#')
		{
			if (!ft_strcmp(str + 2, "end") && lemin->props == -1)
				lemin->props = END;
			else if (!ft_strcmp(str + 2, "start") && lemin->props == -1)
				lemin->props = START;
			else
				error(" :: command not found");
		}
	}
	else if (lemin->data_type == ANTS_NBR)
		get_ants(lemin, str);
	else
	{
		if (lemin->data_type == ROOMS)
			get_rooms(lemin, str);
		if (lemin->data_type == TUBES)
			get_tubes(lemin, str);
	}
}

int		get_data(t_lemin *lemin)
{
	char	*str;
	int		ret;

	str = NULL;
	(void)lemin;
	while ((ret = get_next_line(0, &str)) && ret != -1)
		treat_line(lemin, str);
	if (ret == -1)
		error(" :: ret = -1");
	if (!lemin->start || !lemin->end)
		error(" :: no start or end");
	return (0);
}
