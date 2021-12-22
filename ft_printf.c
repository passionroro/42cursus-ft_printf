/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:29:53 by rohoarau          #+#    #+#             */
/*   Updated: 2021/11/30 16:00:37 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checktype(char p, va_list ap)
{
	int	count;

	count = 0;
	if (p == 'c')
		count = ft_printchar(va_arg(ap, int));
	if (p == 's')
		count = ft_printstr(va_arg(ap, char *));
	if (p == 'd' || p == 'i')
		count = ft_printint(va_arg(ap, int));
	if (p == 'u')
		count = ft_printuint(va_arg(ap, unsigned int));
	if (p == '%')
		count = write (1, "%", 1);
	if (p == 'x' || p == 'X')
		count = ft_printhex(va_arg(ap, unsigned int), p);
	if (p == 'p')
		count = write (1, "0x", 2) + ft_printptr(va_arg(ap, size_t), p);
	return (count);
}

int	ft_callprintf(const char *p, va_list ap)
{
	int	count;

	count = 0;
	while (*p)
	{
		while (*p != '%' && *p)
		{
			ft_putchar_fd(*p, 1);
			p++;
			count++;
		}
		if (*p == '%')
		{
			p++;
			count += ft_checktype(*p, ap);
			p++;
		}
	}
	return (count);
}

int	ft_printf(const char *p, ...)
{
	int			count;
	va_list		ap;

	va_start(ap, p);
	count = ft_callprintf(p, ap);
	va_end(ap);
	return (count);
}

int	main()
{
	printf("%d\n", printf("  %s %s | res:", "hello", ""));
	printf("%d\n", ft_printf("  %s %s | res:", "hello", ""));
	printf("%d\n", printf("  %d %d %d %d %d | res:", 2147483647, 421, 0, -1, -2147483648));
	printf("%d\n", ft_printf("  %d %d %d %d %d | res:", 2147483647, 421, 0, -1, -2147483648));
	printf("%d\n", printf("  %u %u %u %u %u | res:", 2147483647, 421, 0, -1, -2147483648));
	printf("%d\n", ft_printf("  %u %u %u %u %u | res:", 2147483647, 421, 0, -1, -2147483648));
	printf("%d\n", printf("  %a  | res:", "hello"));
	printf("%d\n", ft_printf("  %a  | res:", "hello"));
	printf("%d\n", printf("  %a  | res:", "hello"));
	printf("%d\n", ft_printf("  %a  | res:", "hello"));
	printf("%d\n", printf("  %a  | res:", "hello"));
	printf("%d\n", ft_printf("  %a  | res:", "hello"));
	printf("%d\n", printf("  %a  | res:", "hello"));
	printf("%d\n", ft_printf("  %a  | res:", "hello"));
	printf("%d\n", printf("  %a  | res:", "hello"));
	printf("%d\n", ft_printf("  %a  | res:", "hello"));
	printf("%d\n", printf("  %a  | res:", "hello"));
	printf("%d\n", ft_printf("  %a  | res:", "hello"));
}
