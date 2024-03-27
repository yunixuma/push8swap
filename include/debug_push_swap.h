/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_push_swap.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/28 05:32:01 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_PUSH_SWAP_H
# define DEBUG_PUSH_SWAP_H

# include "debug_common.h"

void	pswp_debug_print_both(t_lst **lsts, t_node **nodes);
void	pswp_debug_print_lsts(t_lst **lsts);
void	pswp_debug_print_nodes(t_node **nodes);
int		ft_lstsize(t_lst *lst);

#endif
