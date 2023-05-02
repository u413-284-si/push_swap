/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:46:42 by sqiu              #+#    #+#             */
/*   Updated: 2023/05/02 11:29:25 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_CHECK_H
# define INPUT_CHECK_H

/* ====== FUNCTIONS ====== */

void	ft_input_check(char **argv, t_meta *meta);
int		ft_is_num(char *s);
void	ft_no_duplicates(t_meta *meta);


#endif