/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:24:55 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/26 15:53:21 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ====== LIBRARIES ====== */

# include <fcntl.h>			        /* required for opening files */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>				/* required for INT_MIN and INT_MAX*/
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../libft/gnl/get_next_line_bonus.h"

/* ====== DEFINITIONS ====== */

# define ASC 1
# define DSC 0

/* ====== STRUCTS ====== */

typedef struct s_stack
{
	int	size;
	int	top;
	int	*arr;
}	t_stack;

typedef struct s_meta
{
	int		num_count;
	t_stack	a;
	t_stack	b;
	t_list	*ops_head;
}			t_meta;

#endif