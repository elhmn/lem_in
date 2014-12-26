#include "lem_in.h"
#include "debug.h"

t_nod	*if_match(char *str, t_list **hashtab)
{
	int		i;
	int		len;
	t_list	*tmp;

	len = 0;
	i = -1;
	if (hashtab)
	{
		while (++i < MOD_SIZE)
		{
			if (hashtab[i])
			{
				tmp = hashtab[i];
				while (tmp)
				{
					len = ft_strlen(tmp->nod->name);
					if (!ft_strncmp(tmp->nod->name, str, len))
					{
						//lier les deux elements
//						print_type("str exist && str" , str, CHAR);
						//print_type("str + i" , str + len, CHAR);
						return (tmp->nod);
					}
					tmp = tmp->next;
				}
			}
		}
	}
	return (NULL);
}

void	nod_addelem(t_nod *nod1, t_nod *nod2)
{
	t_list	*tmp;
	t_list	*elem;

	tmp = NULL;
	elem = NULL;
	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		error(" :: malloc elem");
	elem->nod = nod2;
	elem->next = NULL;
	if (!nod1->links)
	{
		nod1->links = elem;
		tmp = nod1->links;
	}
	else
	{
		tmp = nod1->links;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}

void	add_link(t_nod *nod1, t_nod *nod2)
{

	if (nod1 && nod2)
	{
		nod_addelem(nod1, nod2);
		nod_addelem(nod2, nod1);
	}
	else
		error("");
}


int		hashtab_chr(t_list **hashtab, void *data)
{
	char 		*str;
	t_nod		*nod1;
	t_nod		*nod2;
	int			len;

	str = (char*)data;
	if (str && hashtab)
	{
		if ((nod1 = if_match(str, hashtab)))
		{
			len = ft_strlen(nod1->name);
			if ((nod2 = if_match(str + len + 1, hashtab)))
			{
				add_link(nod1, nod2);
				return (1);
			}
		}
	}
	return (0);
}

int		is_tube(char *str, t_lemin *lemin)
{
	if (str && lemin)
	{
		if (hashtab_chr(lemin->hashtab, str))
			return (1);
	}
	return (0);
}

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
			return (0);
		while (str != tmp1 && ft_isdigit(*str))
			str--;
		if (*str == ' ')
		{
			lemin->end_name = str;
			str--;
		}
		else
			return (0);
		if (*tmp1 == 'L')
			error(" :: cant start with L");
		return (1);
	} 
	return (0);
}

void	hashtab_addelem(t_lemin *lemin, t_nod *nod)
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

void	get_props(t_lemin *lemin, t_nod *nod)
{
	nod->props = lemin->props;
	if (lemin->props != -1)
	{
		if (lemin->props == START && lemin->start)
			error(" :: cant get more than one start");
		if (lemin->props == END && lemin->end)
			error(" :: cant get more than one end");
		if (lemin->props == START)
			lemin->start = nod;
		if (lemin->props == END)
			lemin->end = nod;
		lemin->props = -1;
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
	/************** CAN GO IN A FUNCTION  ****/
	nod->links = NULL;
	get_props(lemin, nod);
	lemin->room_nbr++;
	hashtab_addelem(lemin, nod);
	/********* DONT FORGET TO CHECK IF I GOT A END AND A START ***************/
//	debug_nod(nod);
//	ajouter un element a l'element hash du tableau
}
