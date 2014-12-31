/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 06:39:48 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/31 06:40:08 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

void	correct_path(t_lemin *lemin, t_jam *jam)
{
	int		i;
	t_list	*tmpsp;
	int		len;

	i = -1;
	if (lemin && jam)
	{
		while (++i < lemin->room_nbr)
		{
			if (jam[i].nod)
			{
				tmpsp = jam[i].nod;
				len = tmpsp->path_len;
				while (tmpsp)
				{
					if (tmpsp->path_len <= len)
					{

						len = tmpsp;
					}
					tmpsp = tmpsp->next;
				}
			}
		}
	}
}
