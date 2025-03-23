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

void	print_result(const t_bit *result)
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
		ft_printf("\n");
	else
		ft_printf("%c", c);
}

void	handle_sigusr(int code)
{
	t_bit			bit;

	if (code == SIGUSR1)
		bit = 0;
	else if (code == SIGUSR2)
		bit = 1;
	else
		return ;
	enqueue(bit);
}

void	process_queue()
{
	static size_t	bit_len = 0;
	static t_bit	result[BITS + 1];
	t_bit			bit;

	if (get_queue_size() == 0)
		return ;
	bit = dequeue();
	if (bit == DEFAULT)
		return ;
	result[bit_len++] = bit;
	if (bit_len == BITS)
	{
		result[bit_len] = '\0';
		print_result(result);
		while (bit_len > 0)
			result[bit_len--] = 0;
		pause();
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	init_queue();
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	while (1)
		process_queue();
	return (0);
}
