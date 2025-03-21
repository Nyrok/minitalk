/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:48:32 by hkonte            #+#    #+#             */
/*   Updated: 2025/01/31 15:11:55 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_format(const char *format)
{
	char	next_char;

	if (format[0] != '%')
		return (0);
	next_char = format[1];
	if (next_char == 's' || next_char == 'c')
		return (1);
	else if (next_char == 'd' || next_char == 'i')
		return (1);
	else if (next_char == 'x' || next_char == 'X' || next_char == 'u')
		return (1);
	else if (next_char == 'p' || next_char == 'o' || next_char == '%')
		return (1);
	else if (next_char == ' ')
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	void	*arg;

	va_start(args, format);
	len = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		arg = NULL;
		if (check_format(format))
		{
			format++;
			len += format_conversion(arg, *format, args);
		}
		else
		{
			len++;
			write(1, format, 1);
		}
		format++;
	}
	return (len);
}
