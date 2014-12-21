/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 17:10:49 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/15 17:44:57 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static void		reduce(unsigned long *hash)
{
	*hash = *hash % MOD_SIZE;
}

unsigned long	hash1(char *str)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	if (hash > MOD_SIZE)
		reduce(&hash);
	return (hash);
}

unsigned long	hash2(char *str)
{
	unsigned long	hash;
	int				c;

	hash = 0;
	while ((c = *str++))
		hash = c + (hash << 6) + (hash << 16) - hash;
	if (hash > 50000)
	//	reduce(&hash);
	hash = hash % 50000;
	return (hash);
}

unsigned long	hash3(char *str)
{
	unsigned long	hash;
	int				c;

	hash = 0;
	while ((c = *str++))
		hash += c;
	if (hash >= MOD_SIZE)
		reduce(&hash);
	return (hash);
}
