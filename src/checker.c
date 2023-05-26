/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:28:51 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/26 19:17:25 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/checker.h"
#include "../inc/input_check.h"
#include "../inc/terminate.h"
#include "../inc/initiate.h"
#include "../inc/ops.h"
#include "../inc/utils.h"

/* This program takes numbers as initial input and then reads
from stdin. It aborts and gives an error under following
circumstances:

* if the input is non-numerical
* if the input contains empty strings
* if the input is out of bounds of an int
* if the input contains duplicates
* if the reading from stdin does not conform to a set of
predefined operations

If every input is valid, the operations are executed and 
the sorted stack is evaluated whether it is in ascending order. */

int	main(int argc, char **argv)
{
	t_meta	meta;
	int		i;

	if (argc == 1)
		exit(1);
	i = 0;
	while (++i < argc)
	{
		if (*argv[i] == '\0')
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
	ft_input_check(argv, &meta);
	ft_initiate(argv, &meta);
	ft_no_duplicates(&meta);
	ft_read_stdin(&meta);
	if (ft_is_sorted(meta.a, ASC))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_backtozero(&meta, false);
	return (0);
}

/* This function reads from stdin and if there is no input it breaks
out of the loop. If there is input, this will be evaluated according
to the criteria mentioned above. It all are met, the operation is
executed. */

void	ft_read_stdin(t_meta *meta)
{
	char	*buf;

	while (1)
	{
		buf = get_next_line(0);
		if (!buf)
			break ;
		ft_check_op(meta, buf);
		ft_execute_op(meta, buf);
		free(buf);
	}
}

/* This function verifies that the string provided is a valid operation and
that its syntax is correct (getnextline returns with the newline).
If not the program closes and returns an error message. */

void	ft_check_op(t_meta *meta, char *op)
{
	int	len;

	if (!op)
		return ;
	len = ft_strlen(op);
	if (!(len == 3 || len == 4))
		ft_backtozero(meta, true);
	if (ft_strncmp(op, "sa\n", 3) && ft_strncmp(op, "sb\n", 3)
		&& ft_strncmp(op, "ss\n", 3) && ft_strncmp(op, "pa\n", 3)
		&& ft_strncmp(op, "pb\n", 3) && ft_strncmp(op, "ra\n", 3)
		&& ft_strncmp(op, "rb\n", 3) && ft_strncmp(op, "rr\n", 3)
		&& ft_strncmp(op, "rra\n", 4) && ft_strncmp(op, "rrb\n", 4)
		&& ft_strncmp(op, "rrr\n", 4))
		ft_backtozero(meta, true);
}

/* This function calls the operation according to the string provided.*/

void	ft_execute_op(t_meta *meta, char *op)
{
	if (!op)
		return ;
	if (!(ft_strncmp(op, "sa\n", 3)))
		ft_sa(meta, false);
	else if (!(ft_strncmp(op, "sb\n", 3)))
		ft_sb(meta, false);
	else if (!(ft_strncmp(op, "ss\n", 3)))
	{
		ft_sa(meta, false);
		ft_sb(meta, false);
	}
	else if (!(ft_strncmp(op, "pa\n", 3)))
		ft_pa(meta, false);
	else if (!(ft_strncmp(op, "pb\n", 3)))
		ft_pb(meta, false);
	else if (!(ft_strncmp(op, "ra\n", 3)))
		ft_ra(meta, false);
	else if (!(ft_strncmp(op, "rb\n", 3)))
		ft_rb(meta, false);
	else
		ft_execute_op_cont(meta, op);
}

/* This function calls the operation according to the string provided.*/

void	ft_execute_op_cont(t_meta *meta, char *op)
{
	if (!(ft_strncmp(op, "rr\n", 3)))
	{
		ft_ra(meta, false);
		ft_rb(meta, false);
	}
	else if (!(ft_strncmp(op, "rra\n", 4)))
		ft_rra(meta, false);
	else if (!(ft_strncmp(op, "rrb\n", 4)))
		ft_rrb(meta, false);
	else if (!(ft_strncmp(op, "rrr\n", 4)))
	{
		ft_rra(meta, false);
		ft_rrb(meta, false);
	}
}
