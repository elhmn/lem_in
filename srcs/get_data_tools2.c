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
						return (tmp->nod);
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
	int		i;

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
		{
			if (!(i = ft_strcmp(tmp->nod->name, nod2->name)))
				break;
			tmp = tmp->next;
		}
		i = ft_strcmp(tmp->nod->name, nod2->name);
		if (i)
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
