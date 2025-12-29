/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:44:46 by rodcaeta          #+#    #+#             */
/*   Updated: 2025/12/17 15:44:46 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf_char(int c);
int	ft_printf_str(char *s);
int ft_printf_nbr(long nb);
int ft_printf_hexa(unsigned long nb, char base);
int	fmt_check(const char type, va_list args);
int	ft_printf(const char *str, ...);

#endif

