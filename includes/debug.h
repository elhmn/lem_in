/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 07:31:22 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/27 07:31:23 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	debug_nod(t_nod *nod);
void	print_hashtab(t_list **hashtab);
void	debug_links(t_nod *nod);
#endif
