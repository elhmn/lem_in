#include "lemin.h"

static t_listsp	*copy_listsp(t_listsp *pathsp)
{
	t_listsp	*sp_tmp;
	t_listsp	*tmp_1;
	t_listsp	*tmp_2;

	if (!path_sp)
		check_errors(MALLOC, __FILE__, "path_sp");
	if (!(sp_tmp = (t_listsp*)malloc(sizeof(t_listsp))))
		check_errors(MALLOC, __FILE__, "sp_tmp");
	tmp_1 = pathsp;
	tmp_2 = sp_tmp;
	while (tmp_1)
	{
		if (tmp_1->next)
		{
			if (!(tmp_2->next =
						(t_listsp*)malloc(sizeof(t_listsp))))
				check_errors(MALLOC, __FILE__, "sp_tmp");
		}
		else
			tmp_2->next = NULL;
		tmp_2->list = tmp_1->path;
		tmp_2->path_len = tmp_1->path_len;
		tmp_2->a = 0;
		tmp_1->next = tmp_1;
	}	
	return (sp_tmp);
}

static void	combine(t_listsp **comb, t_listsp *sp, t_jam *jam)
{
	t_jam		*j;
	t_listsp	sp_tmp;

	if (comb)
		check_errors(NUL, __FILE__, "comb");
	if (sp)
		check_errors(NUL, __FILE__, "jam || sp");
	while (j && sp_tmp)
	{
		j = jam;
		while (j)
		{
			sp_tmp = ;
			j = j->next;
		}
	}
}

static void	init_comb(t_listsp **comb)
{
	if (!comb)
		check_errors(NUL, __FILE__, comb);
	if (!(*comb = (t_listsp*)sizeof(t_listsp)))
		check_errors(MALLOC, __FILE__, "*comb");
	(*comb)->list = NULL;
	(*comb)->a = 0;
	(*comb)->index = 0;
	(*comb)->path_len = 0;
	(*comb)->next = NULL;
}

void		get_comb_set(t_lemin *lemin)
{
	t_jam		j_tmp;
	t_listsp	*sp_tmp;

	sp_tmp = NULL;
	if (!lemin)
		check_errors(NUL, __FILE__, "lemin");
	if (!(j_tmp = lemin->jam))
		check_errors(MALLOC, __FILE__, "lemin->jam");
	init_comb(&lemin->comb);
	while (j_tmp)
	{
		sp_tmp = j_tmp->pathsp;
		while (sp_tmp)
		{
			combine(&lemin->comb, sp_tmp, j_tmp->next);
			sp_tmp = sp_tmp->next;
		}
		j_tmp = j_tmp->next;
	}
}
