/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:05:11 by hkonte            #+#    #+#             */
/*   Updated: 2025/03/21 13:11:58 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

char	pow(char *result)
{
	if (!ft_strlen(result))
	{
	  result = malloc((BITS + 1) * sizeof(char));
	  if (!result)
		kill(getpid(), SIGKILL);
	}
	return (result);
}

char	*init_result(char *result)
{
	if (!ft_strlen(result))
	{
	  result = malloc((BITS + 1) * sizeof(char));
	  if (!result)
		kill(getpid(), SIGKILL);
	}
	return (result);
}

void	print_result(char *result)
{
	size_t			i;
	unsigned char	c;

	c = 0;
	i = 0;
	while (i < BITS)
	{
		result[BITS - 1 - i];
		i++;
	}
	if (c == '\0')
		ft_printf("\n");
	free(result);	
}

void	handle_sigusr(int code)
{
	static size_t	bit_len;
	static char		*result;
	int				bit;

	result = init_result(result);
	if (code == SIGUSR1)
		bit = 0;
	else if (code == SIGUSR2)
		bit = 1;
	if (bit_len == BITS - 1)
	{
		print_result(result);
		bit_len = 0;
	}
	else
	{
		if (!bit_len)
			bit_len = 0;
		result[bit_len++] = bit;
	}
}

int		main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	while (1)
	{
		pause();
	}
	return (0);
}
