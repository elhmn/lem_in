/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comb_set_tools1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 11:53:32 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/30 13:11:30 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			add_comb_tmp(t_jam *comb, t_listsp *sp)
{
	t_listsp	*sp_tmp;

	if (comb)
	{
		sp_tmp = comb->pathsp;
		while (sp_tmp->next)
			sp_tmp = sp_tmp->next;
		sp_tmp->next = (sp) ? new_listsp_from_listsp(NULL, sp) : NULL;
	}
}

void			remove_sp(t_listsp *sp_tmp)
{
	if (sp_tmp)
	{
		if (!sp_tmp->next)
			free(sp_tmp);
		else
		{
			while (sp_tmp->next->next)
				sp_tmp = sp_tmp->next;
			free(sp_tmp->next);
			sp_tmp->next = NULL;
		}
	}
}

void			remove_sp_to_comb_tmp(t_jam *comb)
{
	t_listsp	*sp_tmp;

	if (comb)
	{
		sp_tmp = comb->pathsp;
		if (!sp_tmp->next)
		{
			free(sp_tmp);
			comb->pathsp = NULL;
		}
		else
		{
			while (sp_tmp->next->next)
				sp_tmp = sp_tmp->next;
			free(sp_tmp->next);
			sp_tmp->next = NULL;
		}
	}
}

t_listsp		*copy_tmp_sp(t_listsp *psp)
{
	t_listsp	*sp;
	t_listsp	*tmp;
	t_listsp	*tmp2;
	t_listsp	*sp_tmp;

	sp = NULL;
	if (!(sp_tmp = psp))
		return (NULL);
	else
		sp = new_listsp_from_listsp(NULL, sp_tmp);
	tmp = sp;
	sp_tmp = sp_tmp->next;
	while (sp_tmp)
	{
		tmp2 = new_listsp_from_listsp(NULL, sp_tmp);
		tmp->next = tmp2;
		sp_tmp = sp_tmp->next;
		tmp = tmp->next;
	}
	return (sp);
}

t_listsp		*copy_comb_tmp_sp(t_jam *comb_tmp)
{
	t_listsp	*sp;
	t_listsp	*tmp;
	t_listsp	*tmp2;
	t_listsp	*sp_tmp;

	sp = NULL;
	if (!comb_tmp)
		error();
	if (comb_tmp)
	{
		if (!(sp_tmp = comb_tmp->pathsp))
			return (NULL);
		else
			sp = new_listsp_from_listsp(NULL, sp_tmp);
		tmp = sp;
		sp_tmp = sp_tmp->next;
		while (sp_tmp)
		{
			tmp2 = new_listsp_from_listsp(NULL, sp_tmp);
			tmp->next = tmp2;
			sp_tmp = sp_tmp->next;
			tmp = tmp->next;
		}
	}
	return (sp);
}
