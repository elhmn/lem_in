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

void	treat_line(t_lemin *lemin, char *str)
{
	if (!lemin)
		check_errors(NUL, "lemin", "get_data.c");
	// si ligne vide && autre cond d arret
	if (str && *str == '\0')
		check_errors(NUL, "str", "get_data.c");
	if (lemin->data_type == ANTS_NBR && str)
	{
		lemin->ant_nbr = ft_atoi(str);
		lemin->data_type = ROOMS;
	}
	if (lemin->data_type == ROOMS)
	{

	}
	if (lemin->data_type == TUBES)
	{

	}
	debug_lemin(lemin);
}

int		get_data(t_lemin *lemin)
{
	char	*str;
	int		ret;

	str = NULL;
	lemin = lemin;
	while ((ret = get_next_line(0, &str)) && ret != -1)
	{
		treat_line(lemin, str);
		free(str);
	}
	if (ret == -1)
		check_errors(READ, "get_nex_line", "get_data.c");
	return (0);
}
