/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:44:51 by rohoarau          #+#    #+#             */
/*   Updated: 2021/11/17 11:32:49 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *p, ...);
int		ft_printint(int nb);
int		ft_printchar(char c);
int		ft_printstr(char *s);
int		ft_printuint(unsigned int nb);
int		ft_printhex(unsigned int nb, char p);
int		ft_printptr(size_t nb, char p);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(long int n);

#endif
