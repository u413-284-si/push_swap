/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_dual.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:52:15 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/08 17:23:02 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/ops.h"

/* This function swaps the first two elements of both stack a and b. */

void	ft_ss(t_meta *meta)
{
	ft_sa(meta, false);
	ft_sb(meta, false);
	ft_printf("ss\n");
}

/* This function rotates all elements upwards in both stack a and b. */

void	ft_rr(t_meta *meta)
{
	ft_ra(meta, false);
	ft_rb(meta, false);
	ft_printf("rr\n");
}

/* This function rotates all elements downwards in both stack a and b. */

void	ft_rrr(t_meta *meta)
{
	ft_rra(meta, false);
	ft_rrb(meta, false);
	ft_printf("rrr\n");
}
