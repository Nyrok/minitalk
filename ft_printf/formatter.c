/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:48:32 by hkonte            #+#    #+#             */
/*   Updated: 2025/01/31 15:11:55 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	format_conversion(void *arg, char c, va_list args)
{
	if (c == 's')
		return (format_string(va_arg(args, char *)));
	else if (c == 'c')
		return (format_char(va_arg(args, int)));
	else if (c == 'd' || c == 'i')
		return (format_base(va_arg(args, int), BASE_DEC, 10));
	else if (c == 'x')
		return (format_base(va_arg(args, unsigned int), BASE_HEX, 16));
	else if (c == 'X')
		return (format_base(va_arg(args, unsigned int), BASE_HEX_UPPER, 16));
	else if (c == 'u')
		return (format_base(va_arg(args, unsigned int), BASE_DEC, 10));
	else if (c == 'p')
	{
		arg = va_arg(args, void *);
		if (!arg)
			return (format_string("(nil)"));
		return (format_string("0x")
			+ format_pointer(arg, BASE_HEX, 16));
	}
	else if (c == 'o')
		return (format_base(va_arg(args, unsigned int), BASE_OCT, 8));
	else if (c == '%' || c == ' ')
		return (format_char(c));
	return (0);
}
