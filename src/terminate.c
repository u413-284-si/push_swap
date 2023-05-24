/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:54:33 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/24 01:04:30 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/terminate.h"
#include "../inc/error.h"

/* This function terminates the program with an error message to stdout. */

void	ft_terminate(void)
{
	ft_putendl_fd(ERR_STD, 2);
	exit(1);
}

/* This function resets the memory by freeing any allocated space. If the 
freeing is launched due to an error, an error message will be displayed
by calling ft_terminate. If not the program will be closed w/o a message. */

void	ft_backtozero(t_meta *meta, bool error)
{
	if (meta->a.arr)
		free(meta->a.arr);
	if (meta->b.arr)
		free(meta->b.arr);
	if (meta->ops_head)
		ft_lstclear(&meta->ops_head, &ft_del_content);
	if (error)
		ft_terminate();
	else
		exit(0);
}

/* This function empties the provided array. Its purpose in this program
is to serve as a "delete" for the function freeing the linked list 
("ft_lstclear") which requires a deleting function as argument. */

void	ft_del_content(void *s)
{
	if (!s)
		return ;
	s = "";
}
