/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:45:59 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/12 17:39:53 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/utils.h"
#include "../inc/ops.h"

/* This function locates the smallest value in the given stack. It iterates
starting from the top of the stack which is stack.arr[stack.top].
The top value is initially declared as the minimal value. If a
smaller value is encountered, the min variable and the position
counter (starting from 0) are updated. 
If the top value is min:
	min = stack.arr[stack.top]
	pos = 0
If last value is min:
	min = stack.arr[0]
	pos = stack.top */

int	ft_find_min(t_stack given)
{
	int		pos;
	int		min;
	int		i;
	t_stack	stack;

	pos = 0;
	stack = given;
	min = stack.arr[stack.top];
	i = stack.top + 1;
	while (--i >= 0)
	{
		if (stack.arr[i] < min)
		{
			min = stack.arr[i];
			pos = stack.top - i;
		}
	}
	return (pos);
}

/* This function locates the highest value in the given stack. It iterates
starting from the top of the stack which is stack.arr[stack.top].
The top value is initially declared as the maximal value. If a
higher value is encountered, the max variable and the position
counter (starting from 0) are updated. 
If the top value is min:
	max = stack.arr[stack.top]
	pos = 0
If last value is min:
	max = stack.arr[0]
	pos = stack.top */

int	ft_find_max(t_stack given)
{
	int		pos;
	int		max;
	int		i;
	t_stack	stack;

	pos = 0;
	stack = given;
	max = stack.arr[stack.top];
	i = stack.top + 1;
	while (--i >= 0)
	{
		if (stack.arr[i] > max)
		{
			max = stack.arr[i];
			pos = stack.top - i;
		}
	}
	return (pos);
}

/* This function  rotates the defined stack up- or downwards depending 
on the given string parameter. The amount of rotation steps
required is 
	upwards: starting from 0 to less than position of value to bring on top
	downwards: Total number of values - the position of value to bring on top
*/

void	ft_rotate(char *s, int pos, t_meta *meta, char stack)
{
	int	i;

	i = -1;
	if (!ft_strncmp(s, "up", 2))
	{
		while (++i < pos)
		{
			if (stack == 'a')
				ft_ra(meta, true);
			else
				ft_rb(meta, true);
		}
	}
	else
	{
		while (++i < meta->a.size - pos)
		{
			if (stack == 'a')
				ft_rra(meta, true);
			else
				ft_rrb(meta, true);
		}
	}
}
