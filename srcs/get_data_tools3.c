/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_tools3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 02:45:21 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/30 16:07:19 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "debug.h"

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
