/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:28:51 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/26 15:31:18 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/checker.h"
#include "../inc/input_check.h"
#include "../inc/terminate.h"
#include "../inc/initiate.h"

int	main(int argc, char **argv)
{
	t_meta	meta;

	if (argc == 1)
		exit(1);
	ft_input_check(argv, &meta);
	ft_initiate(argv, &meta);
	ft_no_duplicates(&meta);

	ft_backtozero(&meta, false);
	return (0);
}
