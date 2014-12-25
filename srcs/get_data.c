/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 20:23:53 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/14 03:41:25 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

/*
**	les noeuds seront stocker dans une table de hash (hotrace)
*/

void	get_ants(t_lemin *lemin, char *str)
{
	if (!is_number(str))
		error(" :: str isnt number");
	lemin->ant_nbr = ft_atoi(str);
	lemin->data_type = ROOMS;
}

/*
** is_room permet de verifier le format nom' 'coord_x' 'coord_y
*/

void	get_rooms(t_lemin *lemin, char *str)
{
	lemin = lemin;
	if (!is_room(str, lemin))
	{
		if (!lemin->room_nbr)
			error("no rooms");
		lemin->data_type = TUBES;
		ft_putendl("change type");
	}
	if (lemin->data_type == ROOMS)
		get_room_data(str, lemin);
}

void	get_tubes(t_lemin *lemin, char *str)
{
	char	*tmp;
//	t_list	*links;

	if (lemin && str && !is_tube(str, lemin))
	{
		ft_putendl(str);
		error(" :: is not a tube");
	}
	hashtab_chr(lemin->hashtab, str);
	tmp = ft_strchr(str, '-');
	*tmp = '\0';
/*
	ft_putstr("s1 = [");
	ft_putstr(str);
	ft_putendl("]");
	ft_putstr("s2 = [");
	ft_putstr(tmp + 1);
	ft_putendl("]");
*/
	lemin->data_type = TUBES;
//	add_link(lemin, str, tmp + 1);	
}

void	treat_line(t_lemin *lemin, char *str)
{
	if (!lemin)
		error(" :: lemin");
	if (str && *str == '\0')
		error(" :: ligne vide || str set to NULL");
	//checker que c'est bien un nbr > minint < maxint
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
	//checker que c'est bien une chambre
	else
	{
		if (lemin->data_type == ROOMS)
			get_rooms(lemin, str);
		if (lemin->data_type == TUBES)
			get_tubes(lemin, str);
	}
	//checker que c'est bien un tubes
}

int		get_data(t_lemin *lemin)
{
	char	*str;
	int		ret;

	str = NULL;
	lemin = lemin;
	while ((ret = get_next_line(0, &str)) && ret != -1)
		treat_line(lemin, str);
	if (ret == -1)
		error(" :: ret = -1");
	if (!lemin->start || !lemin->end)
		error(" :: no start or end");
	return (0);
}
