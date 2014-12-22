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

void	get_rooms(t_lemin *lemin, char *str)
{
	char	**split;

	split = NULL;
	lemin = lemin;
	if (!ft_strchr(str, ' ') || *str == 'L')
		error(" :: str is not a room");
	if (!(split = ft_strsplit(str, ' ')) || tab_len(split) != 3)
		error(" :: split to NULL || split != 3 elems");
/*	ft_putstr("split len = [");
	ft_putnbr(tab_len(split));
	ft_putendl("]");
	ft_putendl(*(split + 0));
	ft_putendl(*(split + 1));
	ft_putendl(*(split + 2));
*/
	// stocker le bordel dans la table de hash
}

/*
void	get_tubes(t_lemin *lemin, char *str)
{


}
*/

void	treat_line(t_lemin *lemin, char *str)
{
	if (!lemin)
		error(" :: lemin");
	if (str && *str == '\0')
		error(" :: ligne vide || str set to NULL");
	//checker que c'est bien un nbr > minint< maxint
	if (*str == '#');
	else if (lemin->data_type == ANTS_NBR)
		get_ants(lemin, str);
	//checker que c'est bien une chambres
	else if (lemin->data_type == ROOMS)
		get_rooms(lemin, str);
	//checker que c'est bien un tubes
//	if (lemin->data_type == TUBES)
//		get_tubes(lemin, str);
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
		error(" :: ret = -1");
	return (0);
}
