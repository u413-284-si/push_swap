/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:09:05 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/23 15:21:28 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/utils_ops.h"
#include "../inc/terminate.h"

/* This functions saves the input string into the linked list "ops_head".
If ops_head is still empty, a first node will be created filled with the input
string. */

void	ft_save_op(t_meta *meta, char *s)
{
	t_list	*new;

	new = ft_lstnew(s);
	if (!new)
		ft_backtozero(meta, true);
	ft_lstadd_back(&meta->ops_head, new);
}

/* void	ft_merge_ops(t_meta *meta)
{
	while (meta->ops_head)
	{
		if (meta->ops_head->content == "sa\n"
			&& meta->ops_head->next->content == "sb\n")
		{
			// change sa to ss and delete node with sb
		}
	}
} */

/* This function iterates through the linked list and prints out the content
of each respective node. */

void	ft_print_ops(t_meta *meta)
{
	while (meta->ops_head)
	{
		ft_printf("%s", meta->ops_head->content);
		meta->ops_head = meta->ops_head->next;
	}
}
