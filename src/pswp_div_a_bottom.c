/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_div_a_bottom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/31 02:26:47 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pswp_div_a_bottom_half(t_lst **lsts, int size, int pivot)
{
	int	moved;
	int	rotated;

	moved = N_NOMOVE;
	rotated = N_NOMOVE;
	while ((size > moved * 2 + 1 \
		&& !(pswp_cmp_betop_a(lsts[ID_A], size, pivot, moved) \
		&& pswp_sortchk_whole(lsts[ID_A]) > 0) \
		&& pswp_search_min(lsts[ID_A]) <= pivot) \
		|| lsts[ID_A]->prev->key < pivot + (size + 1) / 2 + 1 || rotated > 0 \
		|| pswp_search_le_back(lsts[ID_A], pivot + 1) > size / 2 - 1)
	{
		if (lsts[ID_A]->key <= pivot)
			moved += pswp_oper_pb(lsts);
		else if (pswp_search_le(lsts[ID_A], pivot) > 0 \
			&& pswp_search_le(lsts[ID_A], pivot) < (size - moved) / 2 - 1)
			rotated += pswp_oper_rx(lsts, ID_A);
		else
			rotated += pswp_oper_rrx(lsts, ID_A);
	}
	return (moved);
}

int	pswp_div_a_bottom(t_lst **lsts, t_node **nodes, ssize_t idx)
{
	int	size;
	int	pivot;

	size = nodes[idx]->size;
	if (size <= SIZE_ZERO)
		size = ft_lstsize(lsts[ID_B]);
	pivot = pswp_calc_pivot_h(nodes[idx]);
	if (SIZE_ZERO < size && size <= SIZE_CHK)
		return (pswp_sort_three_a_bottom(lsts, pivot));
	else if (size <= SIZE_ZERO || pswp_search_min(lsts[ID_A]) > pivot)
		return (N_NOMOVE);
	return (pswp_div_a_bottom_half(lsts, size, pivot));
}
