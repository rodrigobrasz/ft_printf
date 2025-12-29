/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:40:12 by rodcaeta          #+#    #+#             */
/*   Updated: 2025/12/17 15:40:12 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_check(const char type, va_list args);

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		printed_count;
	int		result;

	va_start(args, str);
	printed_count = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '%')
		{
			result = fmt_check(*(++str), args);
			if (result == -1)
				return (va_end(args), -1);
			printed_count += result;
		}
		else if (write (1, str, 1) == -1)
				return (va_end(args), -1);
		else
			printed_count++;
		str++;
	}
	return (va_end(args), printed_count);
}

int	fmt_check(const char type, va_list args)
{
	if (type == 'c')
		return (ft_printf_char(va_arg(args, int)));
	else if (type == 's')
		return (ft_printf_str(va_arg(args, char *)));
	else if (type == 'x' || type == 'X')
		return (ft_printf_hexa(va_arg(args, unsigned int), type));
	else if (type == 'd' || type == 'i')
		return (ft_printf_nbr(va_arg(args, int)));
	else if (type == 'p')
		return (ft_printf_ptr(va_arg(args, unsigned int)));
	else if (type == 'u')
		return (ft_printf_nbr(va_arg(args, unsigned int)));
	else if (type == '%')
		return (ft_printf_char('%'));
	return (-1);
}
