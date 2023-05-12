/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:46:06 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/12 17:40:20 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* ====== Functions ====== */

int		ft_find_min(t_stack given);
int 	ft_find_max(t_stack given);
void	ft_rotate(char *s, int pos, t_meta *meta, char stack);
#endif