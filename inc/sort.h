/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:35:19 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/19 14:28:39 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

/* ====== Functions ====== */
void	ft_sort(t_meta *meta);
void	ft_simple_sort(t_meta *meta);
void	ft_insertion_sort(t_meta *meta);
int		ft_quicksort_a(t_meta *meta, int n);
int		ft_quicksort_b(t_meta *meta, int n);
#endif