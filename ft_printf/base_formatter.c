/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_formatter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:48:32 by hkonte            #+#    #+#             */
/*   Updated: 2025/01/31 15:11:55 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	format_base(long nb, const char *base, long base_len)
{
	int	len;

	len = 0;
	if (nb > base_len - 1)
	{
		len += format_base(nb / base_len, base, base_len);
		len += format_base(nb % base_len, base, base_len);
	}
	else if (nb <= -base_len)
	{
		len += format_char('-');
		len += format_base(-nb / base_len, base, base_len);
		len += format_base(-nb % base_len, base, base_len);
	}
	else if (nb < 0)
	{
		len += format_char('-');
		len += format_char(base[-nb]);
	}
	else
	{
		len += format_char(base[nb]);
	}
	return (len);
}
