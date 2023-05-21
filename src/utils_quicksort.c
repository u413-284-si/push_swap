/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:41:45 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/19 20:25:20 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/utils_quicksort.h"
#include "../inc/terminate.h"
#include "../inc/ops.h"

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
	ft_memmove(buffer, given.arr, sizeof(int) * n);
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

void	ft_fusion_sort_three(t_meta *meta, int n)
{
	if (n == 1) // required?
		ft_pa(meta, true);
	else if (n == 2)
	{
		if (meta->b.arr[meta->b.top] < meta->b.arr[meta->b.top - 1])
			ft_sb(meta, true);
	}
	else if (n == 3)
	{
		while (n || !(meta->a.arr[meta->a.top] < meta->a.arr[meta->a.top - 1]
				&& meta->a.arr[meta->a.top - 1] < meta->a.arr[meta->a.top - 2]))
		{
			if (n == 1 && meta->a.arr[meta->a.top]
				> meta->a.arr[meta->a.top - 1])
				ft_sa(meta, true);
			else if (n == 1 || (n == 2 && meta->b.arr[meta->b.top]
					> meta->b.arr[meta->b.top - 1]) || (n == 3
					&& meta->b.arr[meta->b.top] > meta->a.arr[meta->a.top - 2]))
			{
				ft_pa(meta, true);
				n--;
			}
			else
				ft_sb(meta, true);
		}
	}
}
