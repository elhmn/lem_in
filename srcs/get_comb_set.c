#include "lem_in.h"
#include "debug.h"/*_DEBUG_*/

void		print_firstsp(t_listsp *sp)
{
	if (!sp)
		check_errors(NUL, __FILE__, "sp");
	print_list(sp->list);
	print_type("sp->path_len", &(sp->path_len), INT);
	print_type("sp->a", &(sp->a), INT);
}

static void		add_comb_tmp(t_jam *comb, t_listsp *sp)
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

static void		remove_sp(t_listsp *sp_tmp)
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

static void		remove_sp_to_comb_tmp(t_jam *comb)
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

int			combine(t_jam **comb, t_jam *comb_tmp, t_jam *jam, t_listsp *sp, t_lemin *lemin)
{
	if (!comb)
		check_errors(NUL, __FILE__, "comb");
	if (!sp)
	{
//		remove_sp_to_comb_tmp(comb_tmp);
		return (1);
	}
	if (!jam)
	{
//		remove_sp_to_comb_tmp(comb_tmp);
		return (1);
	}
	add_comb_tmp(comb_tmp, sp);
	ft_putstr("--------------------------------------------------\n\n");/*_DEBUG_*/
	print_listsp(comb_tmp->pathsp);
	ft_putstr("--------------------------------------------------\n\n");/*_DEBUG_*/
//	get_final_pathsp(lemin, comb_tmp);
//	add_copy_comb_tmp(&lemin->comb, comb_tmp);
	lemin->i_tmp += 1;
	if (jam->next)
	{
//		if (sp->next)
//		{
//			remove_sp_to_comb_tmp(comb_tmp);
//			combine(comb, comb_tmp, jam->next, jam->next->pathsp, lemin);
//			add_comb_tmp(comb_tmp, sp);
//		}
		ft_putstr("IN :: combine(comb, comb_tmp, jam->next, jam->next->pathsp, lemin)\n");
		combine(comb, comb_tmp, jam->next, jam->next->pathsp, lemin);
		ft_putstr("OUT :: combine(comb, comb_tmp, jam->next, jam->next->pathsp, lemin)\n");
	}
	remove_sp_to_comb_tmp(comb_tmp);
	ft_putstr("IN :: combine(comb, comb_tmp, jam, sp->next, lemin)\n");
	combine(comb, comb_tmp, jam, sp->next, lemin);
	ft_putstr("OUT :: combine(comb, comb_tmp, jam, sp->next, lemin)\n");
	return (0);
}

t_listsp		*copy_comb_tmp_sp(t_jam *comb_tmp)
{
	t_listsp	*sp;
	t_listsp	*tmp;
	t_listsp	*tmp2;
	t_listsp	*sp_tmp;

	sp = NULL;
	if (!comb_tmp)
		check_errors(NUL, __FILE__, "comb_tmp");
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

void		add_copy_comb_tmp(t_jam **comb, t_jam *comb_tmp)
{
	t_jam	*j_tmp;

	if (!comb)
		check_errors(NUL, __FILE__, "comb");
	if (comb_tmp)
	{
		j_tmp = *comb;
		if (!*comb)
		{
			if (!(*comb = (t_jam*)malloc(sizeof(t_jam))))
				check_errors(MALLOC, __FILE__, "*comb");
			j_tmp = *comb;
		}
		else
		{
			while (j_tmp->next)
				j_tmp = j_tmp->next;
			if (!(j_tmp->next = (t_jam*)malloc(sizeof(t_jam))))
				check_errors(MALLOC, __FILE__, "j_tmp->next");
			j_tmp = j_tmp->next;
		}
		j_tmp->pathsp = (comb_tmp) ? copy_comb_tmp_sp(comb_tmp) : NULL;
		j_tmp->nod = NULL;
		j_tmp->next = NULL;
	}
}

t_listsp *new_listsp_from_listsp(t_listsp **sp, t_listsp *listsp)
{
	t_listsp	*sp_tmp;

	if (!(sp_tmp = (t_listsp*)malloc(sizeof(t_listsp))))
		check_errors(MALLOC, __FILE__, "sp_tmp");
	sp_tmp->list = (listsp) ? listsp->list : NULL;
	sp_tmp->path_len = (listsp) ? listsp->path_len : 0;
	sp_tmp->a = (listsp) ? listsp->a : 0;
	sp_tmp->next = NULL;
	if (sp)
		*sp = sp_tmp;
	return (sp_tmp);
}

static void	init_comb_from_list(t_jam **comb, t_listsp *sp)
{
	t_jam	*j_tmp;

	if (!comb)
		check_errors(NUL, __FILE__, "comb");
	j_tmp = *comb;
	if (!*comb)
	{
		if (!(*comb = (t_jam*)malloc(sizeof(t_jam))))
			check_errors(MALLOC, __FILE__, "*comb");
		j_tmp = *comb;
	}
	new_listsp_from_listsp(&(j_tmp->pathsp), sp);
	j_tmp->nod = NULL;
	j_tmp->next = NULL;
}

static void		delete_comb_tmp(t_jam **comb_tmp)
{
	t_listsp	*sp_tmp;
	t_listsp	*sp;

	if (comb_tmp && *comb_tmp)
	{
		sp = (*comb_tmp)->pathsp;
		sp_tmp = sp;
		while (sp_tmp)
		{
			free(sp_tmp);
			sp_tmp = sp_tmp->next;
		}
		free(*comb_tmp);
		*comb_tmp = NULL;
	}
}

void		get_final_pathsp(t_lemin *lemin, t_jam *comb_tmp)
{
	int		ret;

	ret = 0;
	if (!lemin->sp_tmp)
	{
		sort(&(comb_tmp->pathsp));
		lemin->size = calc(comb_tmp->pathsp, lemin->ant_nbr);
		lemin->sp_tmp = copy_comb_tmp_sp(comb_tmp);
//		ft_putstr("--------------------------------------------------\n\n");/*_DEBUG_*/
//		print_listsp(comb_tmp->pathsp);
//		ft_putstr("--------------------------------------------------\n\n");/*_DEBUG_*/
	}
	else
	{
		if (check_comb(comb_tmp->pathsp))
		{
			sort(&(comb_tmp->pathsp));
			if ((ret = calc(comb_tmp->pathsp, lemin->ant_nbr)) < lemin->size)
			{
				lemin->size = ret;
				remove_sp(lemin->sp_tmp);
				lemin->sp_tmp = copy_comb_tmp_sp(comb_tmp);
//				ft_putstr("--------------------------------------------------\n\n");/*_DEBUG_*/
//				print_listsp(comb_tmp->pathsp);
//				ft_putstr("--------------------------------------------------\n\n");/*_DEBUG_*/
			}
		}
	}
}

void		get_comb_set(t_lemin *lemin)
{
	t_jam		*j_tmp;
	t_jam		*comb_tmp;
	t_listsp	*sp_tmp;

	sp_tmp = NULL;
	comb_tmp = NULL;
	if (!lemin)
		check_errors(NUL, __FILE__, "lemin");
	if (!(j_tmp = lemin->jam))
		check_errors(MALLOC, __FILE__, "lemin->jam");
	lemin->i_tmp = 0;
	while (j_tmp)
	{
		sp_tmp = j_tmp->pathsp;
		while (sp_tmp)
		{
			init_comb_from_list(&comb_tmp, sp_tmp);	
	ft_putstr("--------------------------------------------------\n\n");/*_DEBUG_*/
	print_listsp(comb_tmp->pathsp);
	ft_putstr("--------------------------------------------------\n\n");/*_DEBUG_*/
//			add_copy_comb_tmp(&lemin->comb, comb_tmp);
//			get_final_pathsp(lemin, comb_tmp);
			lemin->i_tmp += 1;
			if (j_tmp->next)
				combine(&lemin->comb, comb_tmp, j_tmp->next, j_tmp->next->pathsp, lemin);
			sp_tmp = sp_tmp->next;
			delete_comb_tmp(&comb_tmp);
		}
		j_tmp = j_tmp->next;
	}
}
