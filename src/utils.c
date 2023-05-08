/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:45:59 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/08 15:20:24 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/utils.h"

/* This function locates the smallest value in stack a. It iterates
starting from the top of the stack which is meta->a.arr[a.top].
The top value is initially declared as the minimal value. If a
smaller value is encountered, the min variable and the position
counter (starting from 0) are updated. 
If the top value is min:
	min = meta->a.arr[meta->a.top]
	pos = 0
If last value is min:
	min = meta->a.arr[0]
	pos = meta->a.top */

int	ft_find_min(t_meta *meta)
{
	int	pos;
	int	min;
	int	i;

	pos = 0;
	min = meta->a.arr[meta->a.top];
	i = meta->num_count;
	while (--i >= 0)
	{
		if (meta->a.arr[i] < min)
		{
			min = meta->a.arr[i];
			pos = meta->a.top - i;
		}
	}
	return (pos);
}

/* This function  rotates stack a up- or downwards depending 
on the given string parameter. The amount of rotation steps
required is 
	upwards: starting from 0 to less than position of value to bring on top
	downwards: Total number of values - the position of value to bring on top
*/

void	ft_rotate(char *s, int pos, t_meta *meta)
{
	int	i;

	i = -1;
	if (s == "up")
		while (++i < pos)
			ft_ra(meta);
	else
		while (++i < meta->num_count - pos)
			ft_rra(meta);
}
