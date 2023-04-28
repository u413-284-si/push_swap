/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:54:33 by sqiu              #+#    #+#             */
/*   Updated: 2023/04/28 10:07:30 by sqiu             ###   ########.fr       */
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
