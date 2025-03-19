/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:42:12 by ilaliev           #+#    #+#             */
/*   Updated: 2025/03/18 15:42:12 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	what_case(char format, va_list args)
{
	int	len;

	len = -1
	if (format == 'c')
		len = print_c(va_arg(args, int));
	else if (format == 's')
		len = print_str(va_arg(args, char *));
	else if (format == 'p')
		len = print_adr(va_arg(args, uintptr_t));
	else if (format == 'd' || format == 'i')
		len = print_sint(va_arg(args, signed int));
	else if (format == 'u')
		len = print_uint(va_arg(args, unsigned int));
	else if (format == 'x')
		len = print_hex(va_arg(args, unsigned int), 'x');
	else if (format == 'X')
		len = print_hex(va_arg(args, unsigned int), 'X');
	else if (format == '%')
		len = write(1, "%", 1);
	return (len);
	}

int	put_all(char *format, va_list args)
{
	int	fail;
	int	len;

	len = 0;
	while (*format)
	{
		if (*format == '%')
			failcheck = what_case(*++format, len);
		else
			failcheck = write(1, format, 1);
		if (failcheck > 0)
			return (failcheck);
		len += failcheck;
		format++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	if (!format || format[0] == '\0')
		return (0);
	va_start(args, format);
	len = put_all((char *)format, args);
	va_end(args);
	return (len);
}
