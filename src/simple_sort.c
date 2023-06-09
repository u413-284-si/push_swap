/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:51:57 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/29 14:29:31 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/simple_sort.h"
#include "../inc/sort.h"
#include "../inc/terminate.h"
#include "../inc/utils.h"
#include "../inc/ops.h"

/* This function sorts two numbers in ascending order. 

Top of stack: 
- last element in array
- shall be smallest value

Going backwards through the array the values shall increase until arr[0] has
the highest value.
*/

void	ft_sort_two(t_meta *meta)
{
	if (meta->a.arr[meta->a.top] > meta->a.arr[meta->a.top - 1])
		ft_sa(meta, true);
}

/* This function sorts three numbers in ascending order. */

void	ft_sort_three(t_meta *meta)
{
	int	first;
	int	sec;
	int	third;

	first = meta->a.arr[meta->a.top];
	sec = meta->a.arr[meta->a.top - 1];
	third = meta->a.arr[meta->a.top - 2];
	if (first < sec)
	{
		if (first < third)
			ft_rra(meta, true);
		if (first < third)
			ft_sa(meta, true);
		else
			ft_rra(meta, true);
	}
	else
	{
		if (first < third)
			ft_sa(meta, true);
		else
			ft_ra(meta, true);
		if (sec > third)
			ft_sa(meta, true);
	}
}

/* This function locates the smallest value in stack a. It is
then rotated to the top of the stack:

If its position within the array is smaller or equal to half
the size of the array, the rotation is upwards otherwise down-
wards in order to be efficient and save steps.

The smallest value is then pushed over to stack b. "Ft_sort_three"
is applied unto the remaining three values. At the end the smallest
value is pushed back to stack a. */

void	ft_sort_four(t_meta *meta)
{
	int	pos;

	pos = ft_find_min(meta->a);
	if (pos <= meta->a.size / 2)
		ft_rotate("up", pos, meta, 'a');
	else
		ft_rotate("down", pos, meta, 'a');
	if (ft_is_sorted(meta->a, ASC))
		ft_backtozero(meta, 0);
	ft_pb(meta, true);
	ft_sort_three(meta);
	ft_pa(meta, true);
}

/* This function works similar to "ft_sort_four" only that it locates
the two smallest values and pushes them consecutively to stack b
before executing "ft_sort_three". */

void	ft_sort_five(t_meta *meta)
{
	int	pos;
	int	i;

	i = -1;
	while (++i < 2)
	{
		pos = ft_find_min(meta->a);
		if (pos <= meta->a.size / 2)
			ft_rotate("up", pos, meta, 'a');
		else
			ft_rotate("down", pos, meta, 'a');
		if (ft_is_sorted(meta->a, ASC))
			break ;
		ft_pb(meta, true);
	}
	if (!(ft_is_sorted(meta->a, ASC)))
		ft_sort_three(meta);
	while (i-- > 0)
		ft_pa(meta, true);
}
