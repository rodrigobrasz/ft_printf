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

int	ft_printf_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_printf_str(char *str)
{
	int		printed_chars;

	printed_chars = 0;
	if (!str)
		str = "(null)";
	while (str[printed_chars])
	{
		if (write(1, &str[printed_chars], 1) == -1)
			return (-1);
		printed_chars++;
	}
	return (printed_chars);
}

int	ft_printf_nbr(long nb)
{
	int		result;
	int		printed_count;

	printed_count = 0;
	if (nb < 0)
	{
		result = write(1, "-", 1);
		if (result == -1)
			return (-1);
		printed_count += result;
		nb = -nb;
	}
	if (nb > 9)
	{
		result = ft_printf_nbr(nb / 10);
		if (result == -1)
			return (-1);
		printed_count += result;
	}
	result = ft_printf_char((nb % 10) + '0');
	if (result == -1)
		return (-1);
	printed_count += result;
	return (printed_count);
}

int	ft_printf_hexa(unsigned long nb, char base)
{
	int		printed_count;
	int		result;
	char	*hex;

	hex = "0123456789abcdef";
	if (base == 'X')
		hex = "0123456789ABCDEF";
	printed_count = 0;
	if (nb > 15)
	{
		result = ft_printf_hexa(nb / 16, base);
		if (result == -1)
			return (-1);
		printed_count += result;
	}
	result = write(1, &hex[nb % 16], 1);
	if (result == -1)
		return (-1);
	printed_count += result;
	return (printed_count);
}

int	ft_printf_ptr(unsigned long ptr)
{
	int	printed_count;
	int	result;

	printed_count = 0;
	if (ptr == 0)
	{
		result = write(1, "(nil)", 5);
		if (result == -1)
			return (-1);
		return (printed_count += result);
	}
	result = write(1, "0x", 2);
	if (result == -1)
		return (-1);
	printed_count += result;
	result = ft_printf_hexa(ptr, 'x');
	if (result == -1)
		return (-1);
	printed_count += result;
	return (printed_count);
}
