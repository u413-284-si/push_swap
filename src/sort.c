/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:35:10 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/15 16:55:47 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/sort.h"
#include "../inc/terminate.h"
#include "../inc/simple_sort.h"
#include "../inc/ops.h"
#include "../inc/utils.h"

/* This function differentiates between the amount of values to be sorted and
assigns a sorting algorithm accordingly. Prior to that it calls a subfunction
to verify whether the values are already sorted and further action is 
needed. */

void	ft_sort(t_meta *meta)
{
	if (ft_is_sorted(meta->a))
		ft_backtozero(meta, 0);
	if (meta->num_count <= 5)
		ft_simple_sort(meta);
	else if (meta->num_count < 64)
		ft_insertion_sort(meta);
	/* else
		ft_quicksort(meta); */
}

/* This function sorts stack a if the number of values it contains is
equal or less than 5. */

void	ft_simple_sort(t_meta *meta)
{
	if (meta->num_count == 2)
		ft_sort_two(meta);
	else if (meta->num_count == 3)
		ft_sort_three(meta);
	else if (meta->num_count == 4)
		ft_sort_four(meta);
	else if (meta->num_count == 5)
		ft_sort_five(meta);
}

/* This function is an implementation of insertion sort. As it is efficient
for small amounts of data values, it is executed for an amount up to 63
values.

The array is split into a sorted and an unsorted part. Values from the un-
sorted part are picked and placed at the correct position in the sorted
part. Best case (= already sorted) every insert requires constant time.

Time complexity:	Average		Best	Worst
					O(n²)		O(n)	O(n²)
Space: const.
Stability: stable */

void	ft_insertion_sort(t_meta *meta)
{
	int	i;
	int	j;
	int	key_index;

	i = 0;
	while (++i < meta->num_count)
	{
		key_index = meta->num_count - i - 1;
		j = key_index + 1;
		if (meta->a.arr[j] > meta->a.arr[key_index])
			ft_sa(meta, true);
		if (meta->b.size >= 2)
			ft_sort_b_insert(meta);
		ft_pb(meta, true);
	}
	ft_sort_b_topdown(meta);
	while (i-- >= 0)
		ft_pa(meta, true);
}

void	ft_sort_b_insert(t_meta *meta)
{
	int	pos;

	pos = ft_find_direct_inferior(meta->b, meta);
	if (pos != 0)
	{
		if (pos <= meta->b.size / 2)
			ft_rotate("up", pos, meta, 'b');
		else
			ft_rotate("down", pos, meta, 'b');
	}
}

void	ft_sort_b_topdown(t_meta *meta)
{
	int	pos;

	pos = ft_find_max(meta->b);
	if (pos != 0)
	{
		if (pos <= meta->b.size / 2)
			ft_rotate("up", pos, meta, 'b');
		else
			ft_rotate("down", pos, meta, 'b');
	}
}
