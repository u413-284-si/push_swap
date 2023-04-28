/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:46:30 by sqiu              #+#    #+#             */
/*   Updated: 2023/04/28 14:58:38 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/input_check.h"
#include "../inc/terminate.h"

/* This function iterates through the provided arguments and verifies whether
they constitute numbers. In case they do not, the program is terminated.

In case several numbers are provided within a single string (in double quotes),
these numbers are checked individually as well. */

void	ft_input_check(char **argv, t_meta *meta)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			len = ft_is_num(&argv[i][j]);
			if (!len)
				ft_terminate();
			j += len;
			meta->num_count++;
		}
		i++;
	}
}

/* This function iterates through the provided string and verifies whether
only digits are present (can be preceded by whitespaces and a single sign).
On success it returns the length of the string, on failure 0. */

int	ft_is_num(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}
