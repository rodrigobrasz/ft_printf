/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinf_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:43:41 by rodcaeta          #+#    #+#             */
/*   Updated: 2025/12/17 15:43:41 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	printed_count;
	char *str

	printed_count = 0;

	while (str[printed_count])
	{
		write (1, &str[printed_count], 1);
		printed_count++;
	}
	return (printed_count);
}

int ft_putnbr(long nb)
{
	int		result;
	int		printed_count;
	char	c;

	printed_count = 0;
	if (nb < 0)
	{
		result = write(1, "-", 1);
		if (result == -1)
			return (-1);
		printed_count += 1;
		nb = -nb;
	}
	if (nb > 9)
	{
		result = ft_putnbr(nb / 10);
		if (result == -1)
			return (-1);
		printed_count += result;
	}
	c = (nb % 10) + '0';
	if (write (1, &c, 1) == -1)
		return (-1);
	printed_count ++;
	return (printed_count)
}

static int ft_puthexa(unsigned long nb, char base)
{
	int printed_count;
	int result;
	char *hex;
	
	hex = "0123456789abcdef";
	if (base == 'X')
		hex = "0123456789ABCDEF";
	printed_count = 0;
	if (nb > 15)
	{
		result = ft_puthexa(nb / 16, base)
		if (result == -1)
			return (-1);
		printed_count += result;
	}
	result = write(1, &hex[nb % 16], 1)
	if (result == -1)
		return (-1);
	printed_count += result;
	return (printed_count);
}

static int ft_putptr(void *ptr)
{
	int conv;
	int	
}