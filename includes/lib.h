/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 20:42:02 by bmbarga           #+#    #+#             */
/*   Updated: 2015/10/30 16:04:18 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

/*
** lib1.c
*/

void	ft_putendl(char *str);
void	ft_putstr(char *str);
void	ft_putchar(int c);
int		tab_len(char **tab);
char	*ft_strsub(char const *s, unsigned int start, size_t size);

void	ft_putnbr(int c);
int		ft_atoi(char *str);
int		ft_isdigit(char str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
int		is_number(char *str);
char	**ft_strsplit(char const *s, char c);

/*
** lib2.c
*/

int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_dashstrlen(char *str);
#endif
