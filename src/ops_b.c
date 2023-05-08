/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:22:00 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/08 17:17:35 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/ops.h"

/* This function swaps the first two elements at the top of stack b. No action
is performed if there is only one element or none. */

void	ft_sb(t_meta *meta, bool print)
{
	int	tmp;

	if (meta->num_count < 2)
		return ;
	tmp = meta->b.arr[meta->b.top];
	meta->b.arr[meta->b.top] = meta->b.arr[meta->b.top - 1];
	meta->b.arr[meta->b.top - 1] = tmp;
	if (print)
		ft_printf("sb\n");
}

/* This function pushes the first element on top of stack a to the top
of stack b. The according top indicators which point to the top element
are updated. No action is performed if stack a is empty. */

void	ft_pb(t_meta *meta, bool print)
{
	if (meta->a.top == -1)
		return ;
	meta->b.top++;
	meta->b.arr[meta->b.top] = meta->a.arr[meta->a.top];
	meta->a.arr[meta->a.top] = 0;
	meta->a.top--;
	meta->b.size++;
	meta->a.size--;
	if (print)
		ft_printf("pb\n");
}

/* This function rotates all elements in stack b upwards to the top.
The top element becomes the last one. */

void	ft_rb(t_meta *meta, bool print)
{
	int	tmp;
	int	i;

	tmp = meta->b.arr[meta->b.top];
	i = -1;
	while (++i < meta->b.size - 1)
		meta->b.arr[meta->b.top - i] = meta->b.arr[meta->b.top - 1 - i];
	meta->b.arr[0] = tmp;
	if (print)
		ft_printf("rb\n");
}

/* This function rotates all elements in stack b downwards to the
bottom. The last will be the first. */

void	ft_rrb(t_meta *meta, bool print)
{
	int	tmp;
	int	i;

	tmp = meta->b.arr[0];
	i = -1;
	while (++i < meta->b.size - 1)
		meta->b.arr[i] = meta->b.arr[i + 1];
	meta->b.arr[meta->b.top] = tmp;
	if (print)
		ft_printf("rrb\n");
}
