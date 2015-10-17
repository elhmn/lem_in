#include "lem_in.h"
#include "check_errors.h"
#include "stdio.h"/*_DEBUG_*/

// TODO checker les conditions d arret de la
// fonction share(t_lemin *lemin, int i_p,
// int a_n, int max);

static void		init_set(t_lemin *lemin)
{
	int			nbr;
	int			i;
	t_listsp	*tmp;

	tmp = NULL;
	if (!lemin)
		check_errors(NUL, __FILE__, "lemin");
	nbr = lemin->path_nbr;
	if (!(lemin->set = (t_uplet*)malloc(sizeof(t_uplet) * nbr)))
		check_errors(MALLOC, __FILE__, "set");
	if (!(tmp = lemin->pathsp))
		check_errors(NUL, __FILE__, "lemin->pathsp");
	i = -1;
	while (++i < nbr && tmp)
	{
		lemin->set[i].l = tmp->path_len;
		lemin->set[i].a = 0;
		lemin->set[i].p = tmp->list;
		lemin->set[i].index = tmp->index;
//		printf("i = [%d] \n", i);/*_DEBUG_*/
//		printf("index = [%d] \n", tmp->index);/*_DEBUG_*/
		tmp = tmp->next;
	}
}

static int		share(t_lemin *lemin, int i_p, int a_n, int max)
{
	if (!(lemin))
		check_errors(NUL, __FILE__, "lemin");
	if (i_p == lemin->path_nbr)
	{
		printf("calcul de couts :\n");/*_DEBUG_*/
		printf("return 1 \n");/*_DEBUG_*/
//		calcul_du_cout();
//		keep();
		return (0);
	}
//	if (i_p > 0 && lemin->set[i_p - 1].a < a_n)
//	{
//		printf("return 2\n");/*_DEBUG_*/
//		return (0);
//	}
	if (i_p)
		lemin->set[i_p].a = max - lemin->set[i_p - 1].a;
	else
		lemin->set[i_p].a = max - a_n;
	// if something
	share(lemin, i_p + 1, a_n, lemin->set[i_p].a);
	//else if something else
	share(lemin, i_p, a_n, lemin->set[i_p].a);
	return (0);
}

int				get_set(t_lemin *lemin)
{
	int		ants_nbr;
//	int		path_nbr;

	if (!lemin)
		check_errors(NUL, __FILE__, "lemin");
	ants_nbr = lemin->ant_nbr + 1;
//	path_nbr = lemin->path_nbr;
	init_set(lemin);
//	printf("ants_nbr = [%d] \n", lemin->ant_nbr);/*_DEBUG_*/

//	distribution des fourmis.

//	distribution par recurence avec un grand nombre de chemin ca pete

	while (--ants_nbr)
	{
		share(lemin, 0, ants_nbr, lemin->ant_nbr);
		printf("ants_nbr = [%d] \n", ants_nbr);/*_DEBUG_*/
	}
	return (0);
}
