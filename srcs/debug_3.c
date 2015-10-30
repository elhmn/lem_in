/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 03:24:04 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/30 03:26:44 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

void			print_list(t_list *list)
{
	ft_putendl("LIST :: \n\tSTART\n");
	if (list)
	{
		ft_putstr("\t\t[");
		while (list)
		{
			ft_putstr(list->nod->name);
			if (list->next)
				ft_putstr("] +--> [");
			list = list->next;
		}
		ft_putendl("]");
	}
	ft_putendl("\tEND\n");
}
