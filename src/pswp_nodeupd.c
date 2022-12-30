/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_nodeupd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/31 02:39:33 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pswp_nodeupd_div_a(t_node **nodes, ssize_t i_org, \
	int (*pf)(t_lst **, t_node **, ssize_t))
{
	ssize_t	i_new;

	i_new = 0;
	while (nodes[i_new] != NULL)
		i_new++;
	if (pf == pswp_div_a_top)
		nodes[i_org]->pos = pswp_nodeseek_bottom(nodes, ID_A) - 1;
	else if (pf == pswp_div_a_bottom)
		nodes[i_org]->pos = pswp_nodeseek_top(nodes, ID_A) + 1;
	if (pf == pswp_div_a_whole && nodes[i_org]->size >= SIZE_LARGE)
	{
		pswp_nodenew_b_tri(nodes, i_org, i_new);
		pswp_nodenew_b_tri2(nodes, i_org, i_new + 1);
		nodes[i_org]->key = pswp_calc_pivot_2t(nodes[i_org]) + 1;
		nodes[i_org]->size = pswp_calc_size_2t(nodes[i_org]);
	}
	else
	{
		pswp_nodenew_b_half(nodes, i_org, i_new);
		nodes[i_org]->key = pswp_calc_pivot_h(nodes[i_org]) + 1;
		nodes[i_org]->size = pswp_calc_size_h(nodes[i_org]);
	}
}

void	pswp_nodeupd_div_b(t_node **nodes, ssize_t i_org, \
	int (*pf)(t_lst **, t_node **, ssize_t))
{
	ssize_t	i_new;

	i_new = 0;
	while (nodes[i_new] != NULL)
		i_new++;
	if (pf == pswp_div_b_top)
		nodes[i_org]->pos = pswp_nodeseek_bottom(nodes, ID_B) - 1;
	else if (pf == pswp_div_b_bottom)
		nodes[i_org]->pos = pswp_nodeseek_top(nodes, ID_B) + 1;
	pswp_nodenew_a_half(nodes, i_org, i_new);
	nodes[i_org]->size /= 2;
}

void	pswp_nodeupd_fix(t_node **nodes, ssize_t i_org)
{
	nodes[i_org]->lst = ID_A;
	nodes[i_org]->pos = pswp_nodeseek_top(nodes, ID_A) + 1;
	nodes[i_org]->fixed = true;
}
