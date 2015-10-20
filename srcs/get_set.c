#include "lem_in.h"
#include "check_errors.h"
#include <stdio.h>/*_DEBUG_*/
#include <unistd.h>/*_DEBUG_*/

# define ABS(x) (x > 0) ? x : -x

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

void		print_set(t_lemin *lemin, int a_n)
{
	int		i;

	i = -1;
	printf("i{\n");
	while (++i < lemin->path_nbr)
	{
		printf("\ta_n = [%d], lemin->set[%d].a = [%d]\n", a_n, i, lemin->set[i].a);
	}
	printf("}\n\n");
}

//	printf("i_p = [%d], a_n = [%d], lemin->set[%d].a = [%d]\n", i_p, a_n, i_p, lemin->set[i_p].a);
static int		share(t_lemin *lemin, int i_p, int a_n, int max)
{
	usleep(100000);
	if (!lemin)
		check_errors(NUL, __FILE__, "lemin");
	if (i_p >= lemin->path_nbr)
	{
		print_set(lemin, a_n);
//		printf("i_p == [%d]\n", i_p);
//		printf("calcul de couts :\n");/*_DEBUG_*/
//		printf("return 0 \n");/*_DEBUG_*/
////		calcul_du_cout();
////		keep();
		return (0);	
	}
	if (!i_p)
		lemin->set[i_p].a = a_n;
	else if (i_p > 0)
		lemin->set[i_p].a = max - lemin->set[i_p - 1].a;
	if (i_p > 0)
		share(lemin, i_p + 1, a_n, lemin->set[i_p].a);
	if (!i_p)
		share(lemin, i_p + 1, a_n, lemin->ant_nbr);
	return (0);
}

int				get_set(t_lemin *lemin)
{
	int		ant_nbr;
//	int		path_nbr;

	if (!lemin)
		check_errors(NUL, __FILE__, "lemin");
	ant_nbr = lemin->ant_nbr;
//	path_nbr = lemin->path_nbr;
	init_set(lemin);
	ant_nbr = lemin->ant_nbr + 1;
//	printf("ants_nbr = [%d] \n", lemin->ant_nbr);/*_DEBUG_*/

//	distribution des fourmis.

//	distribution par recurence avec un grand nombre de chemin ca pete
	while (--ant_nbr)
		share(lemin, 0, ant_nbr, lemin->ant_nbr);
//	printf("ants_nbr = [%d] \n", ant_nbr, lemin->ant_nbr);/*_DEBUG_*/
	return (0);
}
