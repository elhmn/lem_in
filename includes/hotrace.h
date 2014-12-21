/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 21:38:42 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/15 22:00:39 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# define MOD_SIZE 1024

enum  e_hash_size
{
	h1_size = 5500000000000,
	h2_size = 100000,
	h3_size = 10000
};

unsigned long		hash1(char *str);
unsigned long		hash2(char *str);
unsigned long		hash3(char *str);
#endif
