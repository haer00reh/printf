/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:04:44 by haer-reh          #+#    #+#             */
/*   Updated: 2025/11/17 13:58:35 by haer-reh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long nb, char *table)
{
	int	counter;

	counter = 0;
	if (nb >= 16)
		counter += print_hex(nb / 16, table);
	write(1, &table[nb % 16], 1);
	counter++;
	return (counter);
}

int	print_address(void	*addr, char *table)
{
	int				len;
	unsigned long	lu;

	if (addr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	lu = (unsigned long)addr;
	write(1, "0x", 2);
	len = print_hex(lu, table);
	return (len + 2);
}

int	intlen(int n)
{
	int		len;
	long	nb;

	nb = n;
	len = 0;
	if (nb <= 0)
	{
		nb = -nb;
		len++;
	}
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	char	digit;
	int		len;

	len = intlen(nb);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	digit = (nb % 10) + '0';
	write(1, &digit, 1);
	return (len);
}
