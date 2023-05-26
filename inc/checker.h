/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:29:02 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/26 16:29:26 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/* ====== Functions ====== */

void	ft_read_stdin(t_meta *meta);
void	ft_check_op(t_meta *meta, char *op);
void	ft_execute_op(t_meta *meta, char *op);
void	ft_execute_op_cont(t_meta *meta, char *op);

#endif