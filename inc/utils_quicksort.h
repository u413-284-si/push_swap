/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quicksort.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:20:05 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/25 01:34:55 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_QUICKSORT_H
# define UTILS_QUICKSORT_H

/* ====== Functions ====== */

void	ft_fusion_sort_three(t_meta *meta, int n);
void	ft_fusion_push_a(t_meta *meta, int n);
void	ft_sort_stack_a(t_meta *meta, int n);
void	ft_sort_three_within(t_meta *meta, int n);

#endif