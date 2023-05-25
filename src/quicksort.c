/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:11:22 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/25 01:35:30 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/quicksort.h"
#include "../inc/ops.h"
#include "../inc/median.h"
#include "../inc/utils.h"
#include "../inc/utils_quicksort.h"

/* This function is an implementation of quick sort. As it is overall efficient
for high amounts of data values, it is executed for an amount greater than 64
values.

Theory:
Quick Sort is a divide and conquer algorithm. It creates two empty arrays to 
hold elements less than the pivot value and elements greater than the pivot 
value, and then recursively applies itself on the created two sub arrays. As
time complexity is not taken into account for this program the median value
of each array is calculated and chosen as the pivot. This increases the
effectivity of quick sort.

Implementation:
Stack b represents the part with values smaller than the pivot. Stack a contains
values equal or greater than the pivot. All values in stack a are compared to the
pivot and sorted accordingly into stack a or b. As this requires the array to be
rotated (only pushing of top element possible), the rotation eventually needs to 
be reversed to the initial sequence minus the pushed values.
Then the algorithm is recursively calling itself on both stacks while providing
the number of values present in each stack in its call. This number depends on
the previous total n being odd or even.
	Even: 
		Stack a contains (n + 1) / 2 + 1 values
		Stack b contains (n + 1) / 2 - 1 values
	Odd:
		Stack a contains (n + 1) / 2 values
		Stakc b contains (n + 1) / 2 - 1 values
The recursive loop is broken when the stacks reach a total n of 3 or less. In
this case a sorting algorithm respective to each stack is executed. 
Finally all values are sorted in descending order in stack b and are pushed back
to a.

Time complexity:	Average			Best			Worst
					O(n*log(n))		O(n*log(n))		O(n²)
Space: const.
Stability: unstable */

int	ft_quicksort_a(t_meta *meta, int n)
{
	int	median;

	if (ft_is_sorted(meta->a, ASC))
		return (1);
	if (n <= 3)
	{
		ft_sort_stack_a(meta, n);
		return (1);
	}
	ft_get_median(meta, meta->a, n, &median);
	ft_pivot_sort_a(meta, n, median);
	if (n % 2 == 0)
		return (ft_quicksort_a(meta, (n + 1) / 2 + 1)
			&& ft_quicksort_b(meta, (n + 1) / 2 - 1));
	else
		return (ft_quicksort_a(meta, (n + 1) / 2)
			&& ft_quicksort_b(meta, (n + 1) / 2 - 1));
	return (1);
}

/* This function pushes the value to stack b if it is lesser than
the pivot. If not it remains in stack a and the next value is 
brought up for comparison by rotating. Eventually the original
sequence is recoverd by rotating efficiently (or not) according
to which rotation direction requires less steps. */

void	ft_pivot_sort_a(t_meta *meta, int n, int piv)
{
	int	i;
	int	rot_count;

	i = n;
	rot_count = 0;
	while (i-- > 0)
	{
		if (meta->a.arr[meta->a.top] < piv)
			ft_pb(meta, true);
		else if (meta->a.arr[meta->a.top] >= piv)
		{
			ft_ra(meta, true);
			rot_count++;
		}
	}
	if (rot_count <= meta->a.size / 2)
		while (rot_count--)
			ft_rra(meta, true);
	else
		while (rot_count-- && rot_count != meta->a.size)
			ft_ra(meta, true);
}

/* Refer to description of quick sort above.  */

int	ft_quicksort_b(t_meta *meta, int n)
{
	int	median;
	int	i;

	i = meta->b.size;
	if (ft_is_sorted(meta->b, DSC))
		while (i-- > 0)
			ft_pa(meta, true);
	if (n <= 3)
	{
		ft_fusion_sort_three(meta, n);
		return (1);
	}
	ft_get_median(meta, meta->b, n, &median);
	ft_pivot_sort_b(meta, n, median);
	if (n % 2 == 0)
		return (ft_quicksort_a(meta, (n + 1) / 2 + 1)
			&& ft_quicksort_b(meta, (n + 1) / 2 - 1));
	else
		return (ft_quicksort_a(meta, (n + 1) / 2)
			&& ft_quicksort_b(meta, (n + 1) / 2 - 1));
	return (1);
}

/* This function pushes the value to stack a if it is equal or
greater than the pivot. If not it remains in stack b and the 
next value is brought up for comparison by rotating. Eventually 
the original sequence is recoverd by rotating efficiently (or not)
according to which rotation direction requires less steps. */

void	ft_pivot_sort_b(t_meta *meta, int n, int piv)
{
	int	i;
	int	rot_count;

	i = n;
	rot_count = 0;
	while (i-- > 0)
	{
		if (meta->b.arr[meta->b.top] >= piv)
			ft_pa(meta, 1);
		else if (meta->b.arr[meta->b.top] < piv)
		{
			ft_rb(meta, true);
			rot_count++;
		}
	}
	if (rot_count <= meta->b.size / 2)
		while (rot_count-- && meta->b.size != 1)
			ft_rrb(meta, true);
	else
		while (rot_count-- && rot_count != meta->b.size)
			ft_rb(meta, true);
}
