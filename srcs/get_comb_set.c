#include "lem_in.h"

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

static int	combine(t_jam **comb, t_jam *comb_tmp, t_jam *jam, t_listsp *sp)
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

	print_listsp(sp);
	combine(comb, comb_tmp, jam, sp->next);
	//add and copy comb_tmp in comb;
//	add_and_copy_comb_tmp(comb);

	//delete comb_tmp last elem
//	remove_comb(comb_tmp);

//	combine(comb, comb_tmp, jam->next, jam->next->sp); 
	return (0);
}

static void	init_comb(t_jam **comb)//, t_listsp *sp)
{
//	(void)sp;
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

	sp_tmp = NULL;
	comb_tmp = NULL;
	if (!lemin)
		check_errors(NUL, __FILE__, "lemin");
	if (!(j_tmp = lemin->jam))
		check_errors(MALLOC, __FILE__, "lemin->jam");
	init_comb(&lemin->comb);
	init_comb(&comb_tmp);
	printf("BEFORE SEGFAULT\n");/*_DEBUG_*/
	while (j_tmp)
	{
		sp_tmp = j_tmp->pathsp;
		while (sp_tmp)
		{
			//creer la combinaison a 1 element E = (sp_tmp, 0, 0, ..., 0)
//			init_comb(comb_tmp, sp_tmp);
			combine(&lemin->comb, comb_tmp, j_tmp->next, j_tmp->next->pathsp);
			ft_putstr("---------------------------------------------------------\n");/*_DEBUG_*/
			sp_tmp = sp_tmp->next;
//			delete_comb(comb_tmp);
		}
		j_tmp = j_tmp->next;
	}
}
