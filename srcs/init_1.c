#include "lem_in.h"

static void	new_hashtab(t_lemin *lemin)
{
	if (!lemin)
		error(" :: lemin");
	lemin->hashtab = (t_list**)malloc(sizeof(t_list*) * MOD_SIZE);
}

t_lemin	*init_lemin(t_lemin *lemin)
{
	if (!lemin)
	{
		if (!(lemin = (t_lemin*)malloc(sizeof(t_lemin))))
			error(" :: lemin");
	}
	lemin->ant_nbr = 0;
	lemin->data_type = ANTS_NBR;
	new_hashtab(lemin);
	return (lemin);
}
