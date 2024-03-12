/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_push_swap.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/12 09:16:21 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_PUSH_SWAP_H
# define DEBUG_PUSH_SWAP_H

# include "debug_common.h"

void	pswp_debug_print_both(t_lst **lsts, t_node **nodes);
void	pswp_debug_print_lsts(t_lst **lsts);
void	pswp_debug_print_nodes(t_node **nodes);

#endif
