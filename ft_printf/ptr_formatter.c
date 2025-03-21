/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_formatter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:48:32 by hkonte            #+#    #+#             */
/*   Updated: 2025/01/31 15:11:55 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	format_pointer(const void *ptr, char *base, unsigned long base_len)
{
	unsigned long	buffer;
	int				len;
	char			*str;

	buffer = (unsigned long)ptr;
	len = 1;
	while (buffer >= base_len)
	{
		len++;
		buffer /= base_len;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	buffer = (unsigned long)ptr;
	while (len > 0)
	{
		str[--len] = base[buffer % base_len];
		buffer /= base_len;
	}
	len = format_string(str);
	free(str);
	return (len);
}
