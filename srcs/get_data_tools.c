#include "lem_in.h"
#include "debug.h"

int		is_room(char *str, t_lemin *lemin)
{
	char	*tmp1;

	tmp1 = str;
	if (str)
	{
		while (*str)
			str++;
		str--;
		while (str != tmp1 && ft_isdigit(*str))
			str--;
		if (*str == ' ' && ft_isdigit(*(str - 1)))
			str--;
		else
			error("is not room 1");
		while (str != tmp1 && ft_isdigit(*str))
			str--;
		if (*str == ' ')
		{
			lemin->end_name = str;
			str--;
		}
		else
			error("is not a room 2");
		if (*tmp1 == 'L')
			error("is not a room 3");
		return (1);
	} 
	return (0);
}

void	list_addelem(t_lemin *lemin, t_nod *nod)
{
	t_list		*elem;
	t_list		*tmp;
	t_ulong		hash;

	if (!lemin || !nod)
		error(" lemin || nod");
	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		error(" :: elem malloc");
	elem->nod = nod;
	elem->next = NULL;
	hash = hash3(nod->name);
	if (!lemin->hashtab[hash])
		lemin->hashtab[hash] = elem;
	else
	{
		tmp = lemin->hashtab[hash];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}

void	get_room_data(char *str, t_lemin *lemin)
{
	t_nod	*nod;
	char	*tmp;
	char	*car_x;
	char	*car_y;

	nod = NULL;
	tmp = str;
	if (!(nod = (t_nod*)malloc(sizeof(t_nod))))
		error(" :: malloc");
	tmp[lemin->end_name - tmp] = '\0';
	nod->name = tmp;
	car_x = ft_strchr(lemin->end_name + 1, ' ');
	*car_x = '\0';
	nod->coord.x = ft_atoi(lemin->end_name + 1);
	car_y = ft_strchr(car_x + 1, '\0');
	*car_y = '\0';
	nod->coord.y = ft_atoi(car_x + 1);
	list_addelem(lemin, nod);
//	debug_nod(nod);
//	ajouter un element a l'element hash du tableau
}
