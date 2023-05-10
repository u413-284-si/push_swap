/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:15:52 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/09 11:56:23 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/input_check.h"
#include "../inc/terminate.h"
#include "../inc/initiate.h"
#include "../inc/sort.h"

int	main(int argc, char **argv)
{
	t_meta	meta;

	if (argc == 1)
		exit(1);
	ft_input_check(argv, &meta);
	ft_initiate(argv, &meta);
	ft_no_duplicates(&meta);
	ft_sort(&meta);
	
	//printf("%d\n\n", meta.num_count);
	printf("\n");
	int	i = 0;
	while (++i <= meta.a.size)
		printf("%d\n", meta.a.arr[meta.a.size - i]);
	return (0);
}
