/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_div_b_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/31 02:26:00 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_div_b_top_half(t_lst **lsts, int size, int pivot)
{
	int	moved;

	if (size < 1 || pswp_search_max(lsts[ID_B]) <= pivot)
		return (N_NOMOVE);
	moved = N_NOMOVE;
	while ((size > -moved * 2 - 1 || pswp_search_max(lsts[ID_B]) > pivot) \
		&& !(pswp_cmp_betop_b(lsts[ID_B], size, pivot, moved) \
		&& ft_hasflag(pswp_sortchk_whole(lsts[ID_B]), FLAG_DESC)) \
		&& pswp_search_max(lsts[ID_B]) > pivot)
	{
		if (lsts[ID_B]->key > pivot)
			moved += pswp_oper_pa(lsts);
		else
			pswp_oper_rx(lsts, ID_B);
	}
	return (moved);
}

int	pswp_div_b_top(t_lst **lsts, t_node **nodes, ssize_t idx)
{
	int	size;
	int	pivot;

	size = nodes[idx]->size;
	if (size <= SIZE_ZERO)
		size = ft_lstsize(lsts[ID_B]);
	pivot = pswp_calc_pivot_h(nodes[idx]);
	if (size <= SIZE_ZERO || pswp_search_max(lsts[ID_B]) <= pivot)
		return (N_NOMOVE);
	else if (size <= SIZE_CHK)
		return (pswp_sort_three_b_top(lsts, pivot));
	return (pswp_div_b_top_half(lsts, size, pivot));
}
