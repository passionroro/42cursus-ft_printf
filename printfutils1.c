/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfutils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:35:38 by rohoarau          #+#    #+#             */
/*   Updated: 2021/11/17 11:32:29 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (!s)
		return ;
	while (s[++i])
		write (fd, &s[i], sizeof(*s));
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, sizeof(c));
}

static int	len(long int nb)
{
	int	len;

	len = 0;
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

char	*ft_itoa(long int n)
{
	char	*ptr;
	int		i;
	long	nb;

	nb = n;
	i = len(nb);
	ptr = malloc(sizeof(char) * (len(nb) + 1));
	if (ptr == NULL)
		return (NULL);
	if (nb == 0)
		ptr[0] = '0';
	if (nb < 0)
	{
		ptr[0] = '-';
		nb *= -1;
	}
	ptr[i] = '\0';
	while (nb > 0)
	{
		i--;
		ptr[i] = nb % 10 + 48;
		nb /= 10;
	}
	return (ptr);
}

int	ft_printptr(unsigned long int nb, char p)
{
	int	count;

	count = 0;
	if (nb == 0)
		count += write (1, "0", 1);
	if (nb > 0)
	{
		if (nb > 15)
			count += ft_printptr(nb / 16, p);
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
