/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ops.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:09:15 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/24 02:25:04 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_OPS_H
# define UTILS_OPS_H

/* ====== Functions ====== */

void	ft_save_op(t_meta *meta, char *s);
void	ft_print_ops(t_meta *meta);
void	ft_merge_ops(t_meta *meta);
void	ft_merge_check(t_list *temp, t_list *nxt);

#endif