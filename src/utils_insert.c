/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:12:08 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/15 17:39:22 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/utils_insert.h"
#include "../inc/utils.h"

/* This function rotates stack b so that on top is the value directly inferior
to the value on top of stack a. */

void	ft_sort_b_insert(t_meta *meta)
{
	int	pos;

	pos = ft_find_direct_inferior(meta->b, meta);
	if (pos != 0)
	{
		if (pos <= meta->b.size / 2)
			ft_rotate("up", pos, meta, 'b');
		else
			ft_rotate("down", pos, meta, 'b');
	}
}

/* This function rotates stack b so that its max value is on top. */

void	ft_sort_b_topdown(t_meta *meta)
{
	int	pos;

	pos = ft_find_max(meta->b);
	if (pos != 0)
	{
		if (pos <= meta->b.size / 2)
			ft_rotate("up", pos, meta, 'b');
		else
			ft_rotate("down", pos, meta, 'b');
	}
}
