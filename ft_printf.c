/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirvasm <mhirvasm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 07:54:54 by mhirvasm          #+#    #+#             */
/*   Updated: 2025/05/23 11:40:17 by mhirvasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_signed_number(int nb)
{
	int count = 0;

	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));

	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nb = -nb;
		count++;
	}
	count += print_number_base((unsigned long)nb, 10, 0);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int		count;
	int 	return_value;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			return_value = print_format(*format, ap);
			if (return_value == -1)
				return (-1);
			count += return_value;
		}
		else
			count += write(1, format, 1);
	format++;
	}
	va_end(ap);
	return(count);
}
