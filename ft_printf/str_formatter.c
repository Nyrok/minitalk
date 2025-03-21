/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_formatter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:48:32 by hkonte            #+#    #+#             */
/*   Updated: 2025/01/31 15:11:55 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	format_char(const char c)
{
	return (write(1, &c, 1));
}

int	format_string(const char *str)
{
	int	i;

	if (!str)
		return (format_string("(null)"));
	i = 0;
	while (str[i])
	{
		i += format_char(str[i]);
	}
	return (i);
}
