/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:05:01 by haer-reh          #+#    #+#             */
/*   Updated: 2025/11/17 13:58:02 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	char	digit;
	int		len;

	len = 0;
	if (nb > 9)
		len += ft_putunbr(nb / 10);
	digit = (nb % 10) + '0';
	write(1, &digit, 1);
	len++;
	return (len);
}

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	conver(char *format, va_list table, int i)
{
	int	counter;

	counter = 0;
	if (format[i + 1] == 's')
		counter += ft_putstr(va_arg(table, char *));
	else if (format[i + 1] == 'd')
		counter += ft_putnbr(va_arg(table, int));
	else if (format[i + 1] == 'u')
		counter += ft_putunbr(va_arg(table, unsigned int));
	else if (format[i + 1] == 'i')
		counter += ft_putnbr(va_arg(table, int));
	else if (format[i + 1] == 'x')
		counter += print_hex(va_arg(table, unsigned int), "0123456789abcdef");
	else if (format[i + 1] == 'X')
		counter += print_hex(va_arg(table, unsigned int), "0123456789ABCDEF");
	else if (format[i + 1] == 'p')
		counter += print_address(va_arg(table, void *), "0123456789abcdef");
	else if (format[i + 1] == '%')
		counter += ft_putchar('%');
	else if (format[i + 1] == 'c')
		counter += ft_putchar(va_arg(table, int));
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	table;
	int		counter;
	int		i;

	i = 0;
	counter = 0;
	va_start(table, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			counter += conver((char *)format, table, i);
			i++;
		}
		else
			counter += write(1, &format[i], 1);
		i++;
	}
	va_end(table);
	return (counter);
}
