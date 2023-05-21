/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quicksort.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:20:05 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/19 20:21:29 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_QUICKSORT_H
# define UTILS_QUICKSORT_H

/* ====== Functions ====== */

void	ft_swap(int *a, int *b);
void	ft_get_median(t_meta *meta, t_stack given, int n, int *median);
void	ft_fusion_sort_three(t_meta *meta, int n);
#endif