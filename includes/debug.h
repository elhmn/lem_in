#ifndef DEBUG_H
# define DEBUG_H
# define INT	1
# define CHAR	2
# include "lem_in.h"

/*
** debug_1.c
*/

void	debug_lemin(t_lemin *lemin);
void	print_type(char *str, void *data, int type);
#endif
