/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:35:10 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/12 19:33:28 by sqiu             ###   ########.fr       */
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

/* This function verifies whether the given stack is already sorted in ascending
order starting from the smallest value at the top (= arr[total of numbers - 1]).
*/

bool	ft_is_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (stack.size - ++i)
		if (stack.arr[stack.size - i]
			> stack.arr[stack.size - i - 1])
			return (0);
	return (1);
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
	int	key;
	int	key_index;

	i = 0;
	while (++i < meta->num_count)
	{
		key_index = meta->num_count - i - 1;
		key = meta->a.arr[key_index];
		j = key_index + 1;
		if (meta->a.arr[j] > meta->a.arr[key_index])
			ft_sa(meta, true);
		if (meta->b.size >= 2)
			ft_sort_b(meta);
		ft_pb(meta, true);
	}
	while (i-- >= 0)
		ft_pa(meta, true);
}

void	ft_sort_b(t_meta *meta)
{
	int	pos;
	int	i;

	i = -1;
	while (++i < meta->b.size)
	{
		pos = ft_find_max(meta->b); // not max, but value which is closest to value to be pushed over and smaller than it
		if (pos <= meta->b.size / 2)
			ft_rotate("up", pos, meta, 'b');
		else
			ft_rotate("down", pos, meta, 'b');
	}
}
