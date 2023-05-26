/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:41:45 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/26 13:21:24 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/utils_quicksort.h"
#include "../inc/terminate.h"
#include "../inc/ops.h"
#include "../inc/simple_sort.h"

/* This function ends the recursion of quicksort call stack b. If the amount of
remaining values in stack b reaches 3 or less, these numbers are brought
into descending order and than pushed back to stack a. */

void	ft_fusion_sort_three(t_meta *meta, int n)
{
	if (n == 1)
		ft_pa(meta, true);
	if (n == 2 && meta->b.size > 1)
	{
		if (meta->b.arr[meta->b.top] < meta->b.arr[meta->b.top - 1])
			ft_sb(meta, true);
		ft_pa(meta, true);
		ft_pa(meta, true);
	}
	else if (n == 3)
		ft_fusion_push_a(meta, n);
}

/* This function handles the case when there are 3 values in stack b
which are to be sorted. Depending on the order of the top values in
both stacks, different operations are performed to ensure the values
being pushed back to a to arrive in the correct position. */

void	ft_fusion_push_a(t_meta *meta, int n)
{
	while (n || !(meta->a.arr[meta->a.top] < meta->a.arr[meta->a.top - 1]
			&& meta->a.arr[meta->a.top - 1] < meta->a.arr[meta->a.top - 2]))
	{
		if (n == 1 && meta->a.arr[meta->a.top] > meta->a.arr[meta->a.top - 1])
			ft_sa(meta, true);
		else if (n == 1 || (n == 2 && meta->b.arr[meta->b.top]
				> meta->b.arr[meta->b.top - 1]) || (n == 3
				&& meta->b.arr[meta->b.top] > meta->b.arr[meta->b.top - 1]))
		{
			ft_pa(meta, true);
			n--;
		}
		else
			ft_sb(meta, true);
	}
}

/* This function ends the recursion of quicksort call stack a. If the amount of
values on the top of stack a to be sorted reaches 3 or less, these numbers are
brought into ascending order. */

void	ft_sort_stack_a(t_meta *meta, int n)
{
	if (n == 3 && meta->a.size == 3)
		ft_sort_three(meta);
	else if (n == 3)
		ft_sort_three_within(meta, n);
	else if (n == 2)
		if (meta->a.arr[meta->a.top] > meta->a.arr[meta->a.top - 1])
			ft_sa(meta, true);
}

/* This function sorts the top 3 values in stack a in case the total amount of
values in stack a is > 3. Depending on the order of the top values in
stack a, different operations are performed to ensure the values
are being sorted in the right order. */

void	ft_sort_three_within(t_meta *meta, int n)
{
	while (n != 3 || !(meta->a.arr[meta->a.top] < meta->a.arr[meta->a.top - 1]
			&& meta->a.arr[meta->a.top - 1] < meta->a.arr[meta->a.top - 2]))
	{
		if (n == 3 && meta->a.arr[meta->a.top] > meta->a.arr[meta->a.top - 1])
			ft_sa(meta, true);
		else if (n == 3
			&& !(meta->a.arr[meta->a.top] < meta->a.arr[meta->a.top - 2]
				&& meta->a.arr[meta->a.top - 1] < meta->a.arr[meta->a.top - 2]))
		{
			ft_pb(meta, true);
			n--;
		}
		else if (meta->a.arr[meta->a.top] > meta->a.arr[meta->a.top - 1])
			ft_sa(meta, true);
		else if (n++)
			ft_pa(meta, true);
	}
}
