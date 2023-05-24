/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:11:48 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/24 01:38:56 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKSORT_H
# define QUICKSORT_H

/* ====== Functions ====== */

int		ft_quicksort_a(t_meta *meta, int n);
int		ft_quicksort_b(t_meta *meta, int n);
void	ft_pivot_sort_a(t_meta *meta, int n, int piv);
void	ft_pivot_sort_b(t_meta *meta, int n, int piv);

#endif