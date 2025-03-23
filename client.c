/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:05:11 by hkonte            #+#    #+#             */
/*   Updated: 2025/03/21 13:11:58 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

t_bit	*ft_chartobinary(unsigned char c)
{
	t_bit	*result;
	size_t	i;

	result = ft_calloc(BITS, sizeof(t_bit));
	i = BITS - 1;
	while (c > 1)
	{
		result[i] = c % 2;
		c /= 2;
		i--;
	}
	result[i] = c % 2;
	return (result);
}

void	send_char(pid_t pid, const unsigned char c)
{
	t_bit	*binary;
	size_t	i;
	int		signal;

	binary = ft_chartobinary(c);
	i = 0;
	while (i < BITS)
	{
		if (binary[i] == 0)
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		if (kill(pid, signal) == -1)
			break ;
		usleep(1000);
		i++;
	}
}

void	send_message(pid_t pid, const unsigned char *message)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen((char *)message))
	{
		send_char(pid, message[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client <server_pid> <message>", 2);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	send_message(server_pid, (unsigned char *)argv[2]);
}
