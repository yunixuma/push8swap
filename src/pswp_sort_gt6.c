/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_sort_gt6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/29 19:56:33 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pswp_sort_gt6_a(t_lst **lsts, t_node **nodes, ssize_t idx)
{
	int	(*pf)(t_lst **, t_node **, ssize_t);
	int	moved;

	if (nodes[idx]->pos == pswp_nodeseek_top(nodes, ID_A))
	{
		if (nodes[idx]->pos == pswp_nodeseek_bottom(nodes, ID_A))
			pf = pswp_div_a_whole;
		else
			pf = pswp_div_a_top;
	}
	else
		pf = pswp_div_a_bottom;
	moved = (*pf)(lsts, nodes, idx);
	if (nodes[idx]->size <= SIZE_CHK)
		pswp_nodeupd_fix(nodes, idx);
	else
		pswp_nodeupd_div_a(nodes, idx, pf);
	return (moved);
}

static int	pswp_sort_gt6_b(t_lst **lsts, t_node **nodes, ssize_t idx)
{
	int	(*pf)(t_lst **, t_node **, ssize_t);
	int	moved;

	if (nodes[idx]->pos == pswp_nodeseek_top(nodes, ID_B))
	{
		if (nodes[idx]->pos == pswp_nodeseek_bottom(nodes, ID_B))
			pf = pswp_div_b_whole;
		else
			pf = pswp_div_b_top;
	}
	else
		pf = pswp_div_b_bottom;
	moved = (*pf)(lsts, nodes, idx);
	if (nodes[idx]->size <= SIZE_CHK)
		pswp_nodeupd_fix(nodes, idx);
	else
		pswp_nodeupd_div_b(nodes, idx, pf);
	return (moved);
}

int	pswp_sort_gt6(t_lst **lsts, int size)
{
	t_node	**nodes;
	ssize_t	idx;
	int		moved;

	nodes = pswp_nodeinit(size);
	if (nodes == NULL)
		return (N_NOMOVE);
	moved = N_NOMOVE;
	idx = pswp_nodeseek_todiv(nodes);
	while (idx >= 0)
	{
		if (nodes[idx]->lst == ID_A)
			moved = pswp_sort_gt6_a(lsts, nodes, idx);
		else
			moved = pswp_sort_gt6_b(lsts, nodes, idx);
		idx = pswp_nodeseek_todiv(nodes);
		if (pswp_sortchk_whole(lsts[ID_A]) > 0 && lsts[ID_B] == NULL)
			break ;
	}
	pswp_nodeclear(nodes);
	return (moved);
}
