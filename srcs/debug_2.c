/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 12:57:34 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/20 18:56:26 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

void		print_list_nod(t_list *list)
{
	while (list)
	{
		ft_putendl("elem ::");
		debug_nod(list->nod);
		list = list->next;
	}
}
