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

int	main(int argc, char **argv)
{
  (void)argv;
  if (argc != 3)
  {
    ft_putstr_fd("Usage: ./client <server_pid> <message>", 2);
    return (1);
  }
}
