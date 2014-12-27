/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 07:04:34 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/27 07:21:44 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (str)
		while (*str)
			write(1, str++, 1);
}

void	ft_putendl(char *str)
{
	if (str)
	{
		ft_putstr(str);
		ft_putstr("\n");
	}
}

int		tab_len(char **tab)
{
	int		l;

	l = 0;
	if (tab)
	{
		while (*tab && **tab)
		{
			l++;
			tab++;
		}
	}
	return (l);
}

int		is_number(char *str)
{
	if (str)
	{
		while (*str && ft_isdigit(*str))
			str++;
		if (*str)
			return (0);
		return (1);
	}
	return (0);
}
