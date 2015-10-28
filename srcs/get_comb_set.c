#include "lem_in.h"
#include "debug.h"/*_DEBUG_*/

//static t_listsp	*copy_listsp(t_listsp *pathsp)
//{
//	t_listsp	*sp_tmp;
//	t_listsp	*tmp_1;
//	t_listsp	*tmp_2;
//
//	if (!pathsp)
//		check_errors(MALLOC, __FILE__, "path_sp");
//	if (!(sp_tmp = (t_listsp*)malloc(sizeof(t_listsp))))
//		check_errors(MALLOC, __FILE__, "sp_tmp");
//	tmp_1 = pathsp;
//	tmp_2 = sp_tmp;
//	while (tmp_1)
//	{
//		if (tmp_1->next)
//		{
//			if (!(tmp_2->next =
//						(t_listsp*)malloc(sizeof(t_listsp))))
//				check_errors(MALLOC, __FILE__, "sp_tmp");
//		}
//		else
//			tmp_2->next = NULL;
//		tmp_2->list = tmp_1->list;
//		tmp_2->path_len = tmp_1->path_len;
//		tmp_2->a = 0;
//		tmp_1->next = tmp_1;
//	}	
//	return (sp_tmp);
//}



void		print_firstsp(t_listsp *sp)
{
	if (!sp)
		check_errors(NUL, __FILE__, "sp");
	print_list(sp->list);
	print_type("sp->path_len", &(sp->path_len), INT);
	print_type("sp->a", &(sp->a), INT);
}

//static void		add_comb_tmp()
//{
//
//}

/*static*/ int	combine(t_jam **comb, t_jam *comb_tmp, t_jam *jam, t_listsp *sp)
{
	t_jam		*j;
	t_listsp	sp_tmp;

	(void)j;
	(void)sp_tmp;

	// checks d'erreurs basique
	// ---
	if (!comb)
		check_errors(NUL, __FILE__, "comb");

	//--

	// conditions d'arret
	//--
	if (!jam)
	{
		return (1);
	}
	if (!sp)
	{
		//peut etre rajouter des trucs
		return (1);
	}
	//--
	

// do something here but what ?

	//add sp to comb_tmp
//	add_comb_tmp(comb_tmp, sp);

	print_firstsp(sp);
	ft_putstr("-------------- MID ---------------\n");
	combine(comb, comb_tmp, jam, sp->next);
	//add and copy comb_tmp in comb;
//	add_and_copy_comb_tmp(comb);

	//delete comb_tmp last elem
//	remove_comb(comb_tmp);

	// a checker et rajouter debug
	if (jam->next)
	{
		combine(comb, comb_tmp, jam->next, jam->next->pathsp);
	}
	return (0);
}

//new_listsp_from_list(&(j_tmp->pathsp), sp);
/*
static t_jam	*copy_comb_tmp(t_jam *comb_tmp)
{
	t_jam		*j_tmp;
	t_jam		*j_tmp2;
	t_listsp	*sp_tmp;
	t_listsp	*j_sptmp;

	if (!comb_tmp)
		check_errors(NUL, __FILE__, "comb_tmp");
	if (comb_tmp)
	{
		if (!(j_tmp = (t_jam*)malloc(sizeof(t_jam))))
			check_errors(MALLOC, __FILE__, "comb_tmp");	
		sp_tmp = comb_tmp->pathsp;

		j_tmp->pathsp = new_listsp_from_list(NULL, sp_tmp);
		j_tmp->pathsp->next = (sp_tmp->next) ? new_listsp_from_list(NULL, sp_tmp->next) : NULL;
		j_sptmp = j_tmp->pathsp->next;
		j_sptmp = 
		while (sp_tmp)
		{
			j_tmp2->pathsp = new_listsp_from_list(NULL, sp_tmp);
			j_tmp2->pathsp->next = new_listsp_from_list(NULL, sp_tmp->next);

			sp_tmp = sp_tmp->next;
			j_tmp2 = j_tmp2->next;
		}
		j_tmp->nod = NULL;
		j_tmp->next = NULL;
	}
	return (tmp);
}

static void	add_copy_comb_tmp(t_jam **comb, t_jam *comb_tmp)
{
	t_jam	*j_tmp;

	if (comb)
		check_errors(NUL, __FILE__, "comb");
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
	 	if (!(j_tmp->next = (t_jam*)malloc(sizeof())))
			check_errors(MALLOC, __FILE__, "j_tmp->next");
		j_tmp = j_tmp->next;
	}
	j_tmp->pathsp = (comb_tmp) ? comb_tmp->pathsp : NULL;
	j_tmp->nod = NULL;
	j_tmp->next = NULL;
}
*/

static t_listsp *new_listsp_from_list(t_listsp **sp, t_listsp *listsp)
{
	t_listsp	*sp_tmp;

	if (!(sp_tmp = (t_listsp*)malloc(sizeof(t_listsp))))
		check_errors(MALLOC, __FILE__, "*pathsp");
	sp_tmp->list = (listsp) ? listsp->list : NULL;
	sp_tmp->path_len = (listsp) ? listsp->path_len : 0;
	sp_tmp->a = 0;
	sp_tmp->next = NULL;
	if (sp)
		*sp = sp_tmp;
	return (sp_tmp);
	//or do that : is'nt good cus i need to
	//put sp->next to something else than NULL
	//	*sp = listsp;
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
	else
	{
		while (j_tmp->next)
			j_tmp = j_tmp->next;
		if (!(j_tmp->next = (t_jam*)malloc(sizeof(t_jam))))
			check_errors(MALLOC, __FILE__, "j_tmp->next");
		j_tmp = j_tmp->next;
	}
	new_listsp_from_list(&(j_tmp->pathsp), sp);
	j_tmp->nod = NULL;
	j_tmp->next = NULL;
}

static void	init_comb(t_jam **comb)
{
	if (!comb)
		check_errors(NUL, __FILE__, "comb");
	if (!(*comb = (t_jam*)malloc(sizeof(t_jam))))
		check_errors(MALLOC, __FILE__, "*comb");
	(*comb)->pathsp = NULL;
	(*comb)->nod = NULL;
	(*comb)->next = NULL;
}

void		get_comb_set(t_lemin *lemin)
{
	t_jam		*j_tmp;
	t_jam		*comb_tmp;
	t_listsp	*sp_tmp;
	int			i = 0;/*_DEBUG_*/

	sp_tmp = NULL;
	comb_tmp = NULL;
	if (!lemin)
		check_errors(NUL, __FILE__, "lemin");
	if (!(j_tmp = lemin->jam))
		check_errors(MALLOC, __FILE__, "lemin->jam");
	init_comb(&lemin->comb);
//	init_comb(&comb_tmp);
//	printf("BEFORE SEGFAULT\n");/*_DEBUG_*/
	while (j_tmp)
	{
		sp_tmp = j_tmp->pathsp;
		print_type("i", (void*)&i, INT);
//		print_jams(comb_tmp);
		while (sp_tmp)
		{
			//creer la combinaison a 1 element E = (sp_tmp, 0, 0, ..., 0)
//			init_comb_from_list(&comb_tmp, sp_tmp);
			init_comb_from_list(&comb_tmp, sp_tmp);
			if (j_tmp->next)
			{
//				combine(&lemin->comb, comb_tmp, j_tmp->next, j_tmp->next->pathsp);
//				ft_putstr("------------------------------ AFTER COMBINE ---------------------------\n");/*_DEBUG_*/
			}
			sp_tmp = sp_tmp->next;
//			delete_comb(comb_tmp);
		}
		i++;
		j_tmp = j_tmp->next;
	}
	print_jams(comb_tmp);
}
