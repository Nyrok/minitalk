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

volatile sig_atomic_t	g_received_signal = 0;

t_bit	*ft_chartobinary(unsigned char c)
{
	t_bit	*result;
	size_t	i;

	result = ft_calloc(BITS, sizeof(t_bit));
	if (!result)
		exit(1);
	if (!c)
		return (result);
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
			exit(1);
		if (++i == BITS)
			free(binary);
		while (!g_received_signal)
			pause();
		g_received_signal = 0;
	}
}

void	send_message(pid_t pid, const unsigned char *message)
{
	size_t	i;

	i = 0;
	while (message[i] != '\0')
		send_char(pid, message[i++]);
	send_char(pid, '\0');
}

void	handle_ack(int code)
{
	if (code == SIGUSR1)
		g_received_signal = 1;
	else if (code == SIGUSR2)
	{
		ft_printf("Message successfully received by the server, exiting...\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client <server_pid> <message>", 2);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	sa.sa_handler = handle_ack;
	if (sigemptyset(&sa.sa_mask) == -1)
		return (1);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	send_message(server_pid, (unsigned char *)argv[2]);
	while (1)
		pause();
	return (0);
}
