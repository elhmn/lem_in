#include "lem_in.h"
#include "debug.h"

static void		find_jams(t_list *list, t_jam *bool, t_lemin *lemin, int path_len)
{
	int			index;
	t_list		*save;
	t_listsp	*tmp2;
	t_listsp	*tmp;

	save = list;
	while (list)
	{
		index = list->nod->index;
		if (ft_strcmp(list->nod->name, lemin->end->name))
		{
			if (!bool[index].nod)
			{
				bool[index].nod = list->nod;
				if (!(bool[index].path = (t_listsp*)malloc(sizeof(t_listsp))))
					error("");
				bool[index].path->list = save;
				bool[index].path->next = NULL;
				bool[index].path->path_len = path_len;
				//et peut etre path_len
			}
			else
			{
				tmp = bool[index].path;
				while (tmp->next)
					tmp = tmp->next;
				if (!(tmp2 = (t_listsp*)malloc(sizeof(t_listsp))))
					error("");
				tmp2->list = save;
				tmp2->next = NULL;
				tmp->next = tmp2;
			//et peut etre path_len
			}
		}
		list = list->next;
	}
}

static void		jam_init(t_jam *jam, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		jam[i].nod = NULL;
		jam[i].path = NULL;
	}
}

static void		check_obstruction(t_jam *bool, t_listsp *pathsp, t_lemin *lemin)
{
	t_listsp	*tmp;

	tmp = pathsp;
	while (tmp)
	{
		find_jams(tmp->list, bool, lemin, tmp->path_len);
		tmp = tmp->next;
	}
}

static int		is_obstruction(t_jam *bool, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (bool[i].nod)
			return (1);
	}
	return (0);
}

void	print_jam(t_jam *jam)
{
	if (jam && jam->nod)
	{
		ft_putendl("JAM :: ");
		print_type("jam->nod->name", jam->nod->name, CHAR);
		print_type("jam->nod->index", &(jam->nod->index), INT);
		print_listsp(jam->path);
	}
}

void			avoid_trafjams(t_listsp *pathsp, t_lemin *lemin)
{
	t_jam		bool[lemin->room_nbr];

//	while (42)
//	{
		jam_init(bool, lemin->room_nbr);
		check_obstruction(bool, pathsp, lemin);
		if (!is_obstruction(bool, lemin->room_nbr))
			ft_putstr("");
//			break;
//		correct_path(bool);
//	}
}
