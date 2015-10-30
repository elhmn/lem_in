/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:15:13 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/29 18:04:23 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	fun_error_init(t_ferr *f)
{
	if (f)
	{
		f[0] = f_malloc;
		f[1] = f_nul;
		f[2] = f_read;
	}
	else
	{
		ft_putendl("Error : f :: check_errors.c :: set to NULL ");
		exit(EXIT_FAILURE);
	}
}

void		error(void)
{
	ft_putendl("ERROR");
	exit(EXIT_FAILURE);
}

void		check_errors(int code, char *file_name, char *var_name)
{
	int		i;
	t_ferr	fun_error[READ + 1];

	i = -1;
	fun_error_init(fun_error);
	ERR;
	ERR_VAR(var_name);
	ERR_SP;
	ERR_FILE(file_name);
	ERR_SP;
	while (++i < (READ + 1))
		if (i == code)
			fun_error[i]();
	exit(EXIT_FAILURE);
}
