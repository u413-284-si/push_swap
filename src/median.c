/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:28:23 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/25 01:30:40 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/median.h"
#include "../inc/terminate.h"

/* This function identifies the median of a list of numbers provided in stack
"given". To achieve that the list is first copied and sorted in ascending
order starting from index 0.

Then the median value is retrieved at location (n + 1) / 2. The additional -1
accounts for indexing starting at 0. */

void	ft_get_median(t_meta *meta, t_stack given, int n, int *median)
{
	int	i;
	int	j;
	int	*buffer;

	buffer = (int *) malloc(sizeof(int) * n);
	if (!buffer)
		ft_backtozero(meta, 1);
	i = -1;
	while (++i < n)
		buffer[i] = given.arr[given.top - i];
	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
			if (buffer[i] > buffer[j])
				ft_swap(&buffer[i], &buffer[j]);
	}
	*median = buffer[((n + 1) / 2) - 1];
	free(buffer);
}

/* This function interchanges the values of the two pointers provided. */
void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
