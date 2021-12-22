/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfutils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:39:15 by rohoarau          #+#    #+#             */
/*   Updated: 2021/11/17 11:32:33 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	ft_putstr_fd(s, 1);
	while (s[i])
		i++;
	return (i);
}

int	ft_printint(int nb)
{
	int		len;
	char	*ptr;

	len = 0;
	ptr = ft_itoa(nb);
	ft_putstr_fd(ptr, 1);
	free(ptr);
	if (nb == -2147483648)
		return (11);
	if (nb <= 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_printuint(unsigned int nb)
{
	int		len;
	char	*ptr;

	len = 0;
	ptr = ft_itoa(nb);
	len = ft_printstr(ptr);
	free(ptr);
	return (len);
}

int	ft_printhex(unsigned int nb, char p)
{
	int	count;

	count = 0;
	if (nb == 0)
		count += write (1, "0", 1);
	if (nb > 0)
	{
		if (nb > 15)
			count += ft_printhex(nb / 16, p);
		if (nb % 16 < 10)
			count += ft_printchar(nb % 16 + 48);
		if (nb % 16 >= 10 && nb % 16 <= 15)
		{
			if (p == 'x' || p == 'p')
				count += ft_printchar(nb % 16 + 87);
			if (p == 'X')
				count += ft_printchar(nb % 16 + 55);
		}
	}
	return (count);
}
