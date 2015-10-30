/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 07:04:39 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/30 16:03:23 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_dashstrlen(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (*(str + i) && *(str + i) != '-')
			i++;
	}
	return (i);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (*(str + i))
			i++;
	}
	return (i);
}
