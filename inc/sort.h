/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:35:19 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/12 17:13:28 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

/* ====== Functions ====== */
void	ft_sort(t_meta *meta);
bool	ft_is_sorted(t_stack stack);
void	ft_simple_sort(t_meta *meta);
void	ft_insertion_sort(t_meta *meta);
void	ft_sort_b(t_meta *meta);
#endif