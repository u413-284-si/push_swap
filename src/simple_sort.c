/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:51:57 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/05 16:24:35 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/simple_sort.h"

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
		ft_sa(meta);
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
			ft_rra(meta);
		if (first < third)
			ft_sa(meta);
		else
			ft_rra(meta);
	}
	else
	{
		if (first < third)
			ft_sa(meta);
		else
			ft_ra(meta);
			if (sec > third)
				ft_sa(meta);
	}
}
void	ft_sort_four(t_meta *meta)
{
	int	first;
	int	sec;
	int	third;
	int fourth;

	first = meta->a.arr[meta->a.top];
	sec = meta->a.arr[meta->a.top - 1];
	third = meta->a.arr[meta->a.top - 2];
	fourth = meta->a.arr[meta->a.top - 3];
}