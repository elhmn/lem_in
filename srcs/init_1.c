#include "lem_in.h"

static void	new_hashtab(t_lemin *lemin)
{
	int	i;

	i = 0;
	if (!lemin)
		error(" :: lemin");
	lemin->hashtab = (t_list**)malloc(sizeof(t_list*) * MOD_SIZE);
	while (i < MOD_SIZE)
		lemin->hashtab[i++] = NULL;
}

t_lemin	*init_lemin(t_lemin *lemin)
{
	if (!lemin)
	{
		if (!(lemin = (t_lemin*)malloc(sizeof(t_lemin))))
			error(" :: lemin");
	}
	lemin->ant_nbr = 0;
	lemin->room_nbr = 0;
	lemin->end_name = NULL;
	lemin->start = NULL;
	lemin->end = NULL;
	lemin->props = -1;
	lemin->data_type = ANTS_NBR;
	new_hashtab(lemin);
	return (lemin);
}
