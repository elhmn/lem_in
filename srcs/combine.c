/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 12:04:38 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/30 12:12:13 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			combine(t_jam *comb_tmp, t_jam *jam, t_listsp *sp, t_lemin *lemin)
{
	if (!sp || !jam)
		return (1);
	add_comb_tmp(comb_tmp, sp);
	get_final_pathsp(lemin, comb_tmp);
	lemin->i_tmp += 1;
	if (jam->next)
	{
		if (sp->next)
		{
			remove_sp_to_comb_tmp(comb_tmp);
			combine(comb_tmp, jam->next, jam->next->pathsp, lemin);
			add_comb_tmp(comb_tmp, sp);
		}
		combine(comb_tmp, jam->next, jam->next->pathsp, lemin);
	}
	remove_sp_to_comb_tmp(comb_tmp);
	combine(comb_tmp, jam, sp->next, lemin);
	return (0);
}
