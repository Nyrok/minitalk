/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:05:11 by hkonte            #+#    #+#             */
/*   Updated: 2025/03/21 13:11:58 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"
#include <stdio.h>

t_bit   queue[QUEUE_SIZE];

void    init_queue()
{
    size_t  i;

    i = 0;
    while (i < QUEUE_SIZE)
        queue[i++] = DEFAULT;
}

size_t    get_queue_size()
{
    size_t  i;

    i = 0;
    while (i < QUEUE_SIZE && queue[i] != DEFAULT)
        i++;
    return (i);
}

void    enqueue(t_bit bit)
{
    size_t queue_size;

    queue_size = get_queue_size();
    queue[queue_size] = bit;
}

t_bit    dequeue()
{
    t_bit   bit;
    size_t  i;
    size_t  size;

    bit = queue[0];
    if (bit == DEFAULT)
        return (DEFAULT);
    i = 1;
    size = get_queue_size();
    printf("%zu", size);
    while (i < size && size < QUEUE_SIZE)
    {
        queue[i - 1] = queue[i];
        i++;
    }
    queue[size - 1] = DEFAULT;
    return (bit);
}