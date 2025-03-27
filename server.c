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

int	ft_pow(int a, int b)
{
	int	result;

	result = a;
	if (b == 0)
		return (1);
	while (b-- > 1)
		result *= a;
	return (result);
}

void	print_result(pid_t pid, const t_bit *result)
{
	size_t			i;
	unsigned char	c;

	c = 0;
	i = 0;
	while (i < BITS)
	{
		c += result[BITS - 1 - i] * ft_pow(2, i);
		i++;
	}
	if (c == 0)
	{
		ft_printf("\n");
		kill(pid, SIGUSR2);
	}
	else
		ft_printf("%c", c);
}

void	handle_sigusr(int sig, siginfo_t *siginfo, void *context)
{
	t_bit			bit;
	static size_t	bit_len = 0;
	static t_bit	result[BITS];

	(void)context;
	if (sig == SIGUSR1)
		bit = 0;
	else if (sig == SIGUSR2)
		bit = 1;
	else
		return ;
	result[bit_len++] = bit;
	if (bit_len == BITS)
	{
		bit_len--;
		print_result(siginfo->si_pid, result);
		while (bit_len > 0)
			result[bit_len--] = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_sigusr;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	ft_printf("%d\n", getpid());
	while (1)
		pause();
	return (0);
}
