#include "lem_in.h"
#include "debug.h"

void print_type(char *str, void *data, int type)
{
	int		*t_int;
	char	*t_char;

	t_int = (int*)data;
	t_char = (char*)data;
	ft_putstr(str);
	ft_putstr(" = [");
	if (type == INT)
		ft_putnbr(*t_int);
	else if (type == CHAR)
		ft_putstr(t_char);
	ft_putendl("]");
}

void	debug_lemin(t_lemin *lemin)
{
	if (!lemin)
		error(" :: lemin");
	print_type("lemin->ant_nbr", &(lemin->ant_nbr), INT);
	print_type("lemin->data_type", &(lemin->data_type), INT);
	//print hashtab
}
