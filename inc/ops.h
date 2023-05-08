/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:22:12 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/08 17:23:29 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

/* ====== Functions ====== */

/* Stack a */
void	ft_sa(t_meta *meta, bool print);
void	ft_pa(t_meta *meta, bool print);
void	ft_ra(t_meta *meta, bool print);
void	ft_rra(t_meta *meta, bool print);

/* Stack b */
void	ft_sb(t_meta *meta, bool print);
void	ft_pb(t_meta *meta, bool print);
void	ft_rb(t_meta *meta, bool print);
void	ft_rrb(t_meta *meta, bool print);

/* Both stacks */
void	ft_ss(t_meta *meta);
void	ft_rr(t_meta *meta);
void	ft_rrr(t_meta *meta);
#endif