/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 02:31:24 by bmbarga           #+#    #+#             */
/*   Updated: 2014/04/27 20:10:30 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char*)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	while (i <= size)
	{
		*(ptr + i) = '\0';
		i++;
	}
	return (ptr);
}
