/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_nodenew_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/29 15:50:54 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pswp_nodenew_b_half(t_node **nodes, ssize_t i_org, ssize_t i_new)
{
	nodes[i_new] = pswp_nodenew_set(nodes[i_org]->key, \
		nodes[i_org]->size / 2, ID_B, \
		pswp_nodeseek_top(nodes, ID_B) + 1);
	nodes[i_new + 1] = NULL;
	return ;
}

void	pswp_nodenew_b_tri(t_node **nodes, ssize_t i_org, ssize_t i_new)
{
	nodes[i_new] = pswp_nodenew_set(pswp_calc_pivot_t(nodes[i_org]) + 1, \
		pswp_calc_size_t(nodes[i_org]), ID_B, \
		pswp_nodeseek_top(nodes, ID_B) + 1);
	nodes[i_new + 1] = NULL;
	return ;
}

void	pswp_nodenew_b_tri2(t_node **nodes, ssize_t i_org, ssize_t i_new)
{
	nodes[i_new] = pswp_nodenew_set(nodes[i_org]->key, \
		nodes[i_org]->size / 3, ID_B, \
		pswp_nodeseek_bottom(nodes, ID_B) - 1);
	nodes[i_new + 1] = NULL;
	return ;
}
