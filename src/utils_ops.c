/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:09:05 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/24 00:38:13 by sqiu             ###   ########.fr       */
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

/* This function iterates the linked list of operations
and merges following operations, if they appear consecutively
(permutation not significant):

	sa + sb = ss
	ra + rb = rr
	rra + rrb = rrr

To achieve this objective the content of the first node is altered
accordingly, the second node deleted and the link connected to the
third node to continue the list. */

void	ft_merge_ops(t_meta *meta)
{
	t_list	*temp;
	t_list	*nxt;

	temp = meta->ops_head;
	while (temp)
	{
		nxt = temp->next;
		if (!(ft_strncmp(temp->content, "sa\n", 3)
				|| ft_strncmp(nxt->content, "sb\n", 3))
			|| !(ft_strncmp(temp->content, "sb\n", 3)
				|| ft_strncmp(nxt->content, "sa\n", 3)))
		{
			temp->content = "ss\n";
			temp->next = nxt->next;
			free(nxt);
		}
		else if (!(ft_strncmp(temp->content, "ra\n", 3)
				|| ft_strncmp(nxt->content, "rb\n", 3))
			|| !(ft_strncmp(temp->content, "rb\n", 3)
				|| ft_strncmp(nxt->content, "ra\n", 3)))
		{
			temp->content = "rr\n";
			temp->next = nxt->next;
			free(nxt);
		}
		else if (!(ft_strncmp(temp->content, "rra\n", 4) 
				|| ft_strncmp(nxt->content, "rrb\n", 4))
			|| !(ft_strncmp(temp->content, "rrb\n", 4)
				|| ft_strncmp(nxt->content, "rra\n", 4)))
		{
			temp->content = "rrr\n";
			temp->next = nxt->next;
			free(nxt);
		}
		temp = temp->next;
	}
}

/* This function iterates through the linked list and prints out the content
of each respective node. */

void	ft_print_ops(t_meta *meta)
{
	t_list	*temp;

	temp = meta->ops_head;
	while (temp)
	{
		ft_printf("%s", temp->content);
		temp = temp->next;
	}
}
