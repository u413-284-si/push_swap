/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:28:32 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/25 01:30:20 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEDIAN_H
# define MEDIAN_H

/* ====== Function ====== */

void	ft_swap(int *a, int *b);
void	ft_get_median(t_meta *meta, t_stack given, int n, int *median);

#endif