#include "lemin.h"

static int	combine(t_lemin *lemin, t_jam *jam, t_listsp *path)
{
	//traitement termine si je suis sur
	//le dernier chemin de la derniere jam
	if (!jam && !path)
	{
		return (0);
	}

	// si je suis sur une jam valide et que
	// je ne suis sur son dernier chemin 
	if (jam && path)
	{
//		add_path(jam);
		combine(lemin, jam, path->next);

	}
	if (jam && !path)
	{
		//
		//put_path(jam);
		//
		combine(lemin, jam->next, jam->next->path);
	}
}

void		get_comb_set(t_lemin *lemin)
{
	t_jam	j_tmp;

	if (!lemin)
		check_errors(NULL, __FILE__, "lemin");
	if (!(j_tmp = lemin->jam))
		check_errors(NULL, __FILE__, "lemin->jam");
//	creer la jam avant ou pendant a voir !! 
	combine(lemin, jam, jam->path);
}
