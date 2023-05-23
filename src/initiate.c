/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:59:15 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/23 13:05:22 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/initiate.h"
#include "../inc/terminate.h"
#include "../inc/input_check.h"

/* This function initiates all variables to default values, retrieves the input
and stores the numerical values in stack a. */

void	ft_initiate(char **argv, t_meta *meta)
{
	ft_init(meta);
	meta->a.arr = (int *) malloc(sizeof(int) * meta->num_count);
	if (!meta->a.arr)
		ft_terminate();
	meta->b.arr = (int *) ft_calloc(meta->num_count, sizeof(int));
	if (!meta->b.arr)
		ft_backtozero(meta, 1);
	ft_parse(argv, meta);
}

/* This function initiates all variables to default values. 
The maxsize of the stacks is equal to the total of numerical values.
The top variable tracks the current index of the value on top of the
stack.*/

void	ft_init(t_meta *meta)
{
	meta->a.size = meta->num_count;
	meta->b.size = 0;
	meta->a.top = meta->num_count - 1;
	meta->b.top = -1;
	meta->ops_head = NULL;
}

/* This function stores the input numbers in stack a represented as an
int array. The first argument/number is at the top of the stack and at the
same time at the end of the array.

	Top of stack	= arr[total of numbers - 1] = argv[1]
	Bottom of stack = arr[0] = argv[total of numbers]

Numbers represented in a string are also parsed and stored.*/

void	ft_parse(char **argv, t_meta *meta)
{
	int	i;
	int	j;
	int	top;
	int	arr_index;

	top = meta->a.size;
	i = 0;
	arr_index = 1;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			meta->a.arr[top - arr_index++] = ft_atoi_mod(&argv[i][j], meta);
			j += ft_is_num(&argv[i][j]);
		}
	}
}

/* This function corresponds to standard atoi of stdlib. However if the values
are not integers (value > 2.147.483.647 or < -2.147.483.648),
the program cleans the memory and exits. */

int	ft_atoi_mod(const char *str, t_meta *meta)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
		if (result * sign > 2147483647)
			ft_backtozero(meta, 1);
		if (result * sign < -2147483648)
			ft_backtozero(meta, 1);
	}		
	return (result * sign);
}