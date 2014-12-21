#include "lem_in.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (str)
		while (*str)
			write(1, str++, 1);
}

void	ft_putendl(char *str)
{
	if (str)
	{
		ft_putstr(str);
		ft_putstr("\n");	
	}
}
