/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:35:10 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/09 10:43:16 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/sort.h"
#include "../inc/terminate.h"
#include "../inc/simple_sort.h"

/* This function differentiates between the amount of values to be sorted and
assigns a sorting algorithm accordingly. Prior to that it calls a subfunction
to verify whether the values are already sorted and further action is 
needed. */

void	ft_sort(t_meta *meta)
{
	if (ft_is_sorted(meta))
		ft_backtozero(meta, 0);
	if (meta->num_count <= 5)
		ft_simple_sort(meta);
/* 	else if (meta->num_count < 64)
		ft_insertion_sort(meta);
	else
		ft_quicksort(meta); */
}

/* This function verifies whether stack a is already sorted in ascending order
starting from the smallest value at the top (= arr[total of numbers - 1]). */

bool	ft_is_sorted(t_meta *meta)
{
	int	i;

	i = 0;
	while (meta->a.arr[meta->num_count - ++i - 1])
		if (meta->a.arr[meta->num_count - i]
			> meta->a.arr[meta->num_count - i - 1])
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
