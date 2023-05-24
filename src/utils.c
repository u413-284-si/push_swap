/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:45:59 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/24 01:08:29 by sqiu             ###   ########.fr       */
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
If the top value is max:
	max = stack.arr[stack.top]
	pos = 0
If last value is max:
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

/* This function locates in the given stack the value closest to the 
value on top of stack a, but which is still inferior to it. It iterates
starting from the top of the stack which is given.arr[given.top].
The top value is initially declared as the closest value. If a
closer value is encountered, the d_inf variable and the position
counter (starting from 0) are updated. 
If the top value is d_inf:
	d_inf = given.arr[given.top]
	pos = 0
If last value is d_inf:
	d_inf = given.arr[0]
	pos = given.top */

int	ft_find_direct_inferior(t_stack given, t_meta *meta)
{
	int		pos;
	int		i;
	long	diff;

	pos = 0;
	diff = INT_MAX;
	i = given.top + 1;
	while (--i >= 0)
	{
		if (meta->a.arr[meta->a.top] - given.arr[i] < diff
			&& given.arr[i] < meta->a.arr[meta->a.top])
		{
			pos = given.top - i;
			diff = meta->a.arr[meta->a.top] - given.arr[i];
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
	int		i;

	i = -1;
	if (!ft_strncmp(s, "up", 2))
	{
		if (stack == 'a')
			while (++i < pos)
				ft_ra(meta, true);
		else
			while (++i < pos)
				ft_rb(meta, true);
	}
	else
	{
		if (stack == 'a')
			while (++i < meta->a.size - pos)
				ft_rra(meta, true);
		else
			while (++i < meta->b.size - pos)
				ft_rrb(meta, true);
	}
}

/* This function verifies whether the given stack is already sorted depending
on the order provided.
In ascending order:
	starting from the smallest value at the top (= arr[total of numbers - 1]).
In descending order:
	starting from the highest value at the top (= arr[total of numbers - 1]).
*/

bool	ft_is_sorted(t_stack stack, int order)
{
	int	i;

	i = 0;
	if (order == 1)
	{
		while (stack.size - ++i)
			if (stack.arr[stack.size - i]
				> stack.arr[stack.size - i - 1])
				return (0);
	}
	else if (order == 0)
	{
		while (stack.size - ++i)
			if (stack.arr[stack.size - i]
				< stack.arr[stack.size - i - 1])
				return (0);
	}
	return (1);
}
