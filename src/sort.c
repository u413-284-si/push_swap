/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:35:10 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/25 01:58:30 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/sort.h"
#include "../inc/terminate.h"
#include "../inc/simple_sort.h"
#include "../inc/quicksort.h"
#include "../inc/ops.h"
#include "../inc/utils.h"
#include "../inc/utils_insert.h"
#include "../inc/utils_quicksort.h"

/* This function differentiates between the amount of values to be sorted and
assigns a sorting algorithm accordingly. Prior to that it calls a subfunction
to verify whether the values are already sorted and further action is 
needed. */

void	ft_sort(t_meta *meta)
{
	if (ft_is_sorted(meta->a, ASC))
		ft_backtozero(meta, 0);
	if (meta->num_count <= 5)
		ft_simple_sort(meta);
	else if (meta->num_count < 64)
		ft_insertion_sort(meta);
	else
		ft_quicksort_a(meta, meta->a.size);
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

Theory:
The array is split into a sorted and an unsorted part. Values from the un-
sorted part are picked and placed at the correct position in the sorted
part. Best case (= already sorted) every insert requires constant time.

Implementation:
Stack b represents the sorted part, stack a the unsorted. The top both values
of stack a are compared and the smaller one swapped to the top. Before pushing
this value x over to stack b the correct position in b is identified and
presented by rotating the directly inferior value y (y < x) in b to the top.
When all but one value (the max of all values) are pushed to b, it is rotated
to a descending order so that its max value is on top.
Finally all values are pushed back to a.

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
