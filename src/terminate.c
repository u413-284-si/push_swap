/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:54:33 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/24 00:48:39 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/terminate.h"
#include "../inc/error.h"

void	ft_terminate(void)
{
	ft_putendl_fd(ERR_STD, 2);
	exit(1);
}

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

void	ft_del_content(void *s)
{
	if (!s)
		return ;
	s = "";
}
