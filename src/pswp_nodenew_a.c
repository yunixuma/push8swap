/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_nodenew_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/29 16:32:28 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pswp_nodenew_a_half(t_node **nodes, ssize_t i_org, ssize_t i_new)
{
	nodes[i_new] = pswp_nodenew_set(pswp_calc_pivot_h(nodes[i_org]) + 1, \
		pswp_calc_size_h(nodes[i_org]), ID_A, \
		pswp_nodeseek_top(nodes, ID_A) + 1);
	nodes[i_new + 1] = NULL;
	return ;
}

void	pswp_nodenew_a_tri(t_node **nodes, ssize_t i_org, ssize_t i_new)
{
	nodes[i_new] = pswp_nodenew_set(pswp_calc_pivot_2t(nodes[i_org]) + 1, \
		pswp_calc_size_2t(nodes[i_org]), ID_A, \
		pswp_nodeseek_top(nodes, ID_A) + 1);
	nodes[i_new + 1] = NULL;
	return ;
}

void	pswp_nodenew_a_tri2(t_node **nodes, ssize_t i_org, ssize_t i_new)
{
	nodes[i_new] = pswp_nodenew_set(pswp_calc_pivot_t(nodes[i_org]) + 1, \
		pswp_calc_size_t(nodes[i_org]), ID_A, \
		pswp_nodeseek_bottom(nodes, ID_A) - 1);
	nodes[i_new + 1] = NULL;
	return ;
}
