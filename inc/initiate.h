/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:59:24 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/02 10:55:28 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIATE_H
# define INITIATE_H

/* ====== FUNCTIONS ====== */

void	ft_initiate(char **argv, t_meta *meta);
void	ft_parse(char **argv, t_meta *meta);
void	ft_init(t_meta *meta);
int		ft_atoi_mod(const char *str, t_meta *meta);

#endif