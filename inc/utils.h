/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:46:06 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/19 14:13:45 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* ====== Functions ====== */

int		ft_find_min(t_stack given);
int		ft_find_max(t_stack given);
int		ft_find_direct_inferior(t_stack given, t_meta *meta);
void	ft_rotate(char *s, int pos, t_meta *meta, char stack);
bool	ft_is_sorted(t_stack stack, int order);
#endif