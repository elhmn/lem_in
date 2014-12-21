/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 16:36:21 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/14 03:11:08 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MY_EOF -1
# define BUFF_SIZE 4

int		get_next_line(int const fd, char **line);
enum	e_str
{
	TMP,
	STR,
	BUFF
};
#endif
