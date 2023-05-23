/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:22:00 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/24 00:19:42 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/ops.h"
#include "../inc/utils_ops.h"


/* This function swaps the first two elements at the top of stack a. No action
is performed if there is only one element or none. */

void	ft_sa(t_meta *meta, bool print)
{
	int	tmp;

	if (meta->num_count < 2)
		return ;
	tmp = meta->a.arr[meta->a.top];
	meta->a.arr[meta->a.top] = meta->a.arr[meta->a.top - 1];
	meta->a.arr[meta->a.top - 1] = tmp;
	if (print)
		ft_save_op(meta, "sa\n");
}

/* This function pushes the first element on top of stack b to the top
of stack a. The according top indicators which point to the top element
are updated. No action is performed if stack b is empty. */

void	ft_pa(t_meta *meta, bool print)
{
	if (meta->b.top == -1)
		return ;
	meta->a.top++;
	meta->a.arr[meta->a.top] = meta->b.arr[meta->b.top];
	meta->b.arr[meta->b.top] = 0;
	meta->b.top--;
	meta->a.size++;
	meta->b.size--;
	if (print)
		ft_save_op(meta, "pa\n");
}

/* This function rotates all elements in stack a upwards to the top.
The top element becomes the last one. */

void	ft_ra(t_meta *meta, bool print)
{
	int	tmp;
	int	i;

	tmp = meta->a.arr[meta->a.top];
	i = -1;
	while (++i < meta->a.size - 1)
		meta->a.arr[meta->a.top - i] = meta->a.arr[meta->a.top - 1 - i];
	meta->a.arr[0] = tmp;
	if (print)
		ft_save_op(meta, "ra\n");
}

/* This function rotates all elements in stack a downwards to the
bottom. The last will be the first. */

void	ft_rra(t_meta *meta, bool print)
{
	int	tmp;
	int	i;

	tmp = meta->a.arr[0];
	i = -1;
	while (++i < meta->a.size - 1)
		meta->a.arr[i] = meta->a.arr[i + 1];
	meta->a.arr[meta->a.top] = tmp;
	if (print)
		ft_save_op(meta, "rra\n");
}
