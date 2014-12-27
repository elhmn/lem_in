/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 07:29:44 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/27 07:30:49 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# define MOD_SIZE 1024

enum	e_hash_size
{
	h1_size = 5500000000000,
	h2_size = 100000,
	h3_size = 10000
};

unsigned long		hash1(char *str);
unsigned long		hash2(char *str);
unsigned long		hash3(char *str);
#endif
