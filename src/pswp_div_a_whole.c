/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_div_a_whole.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/31 03:58:18 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_div_a_whole_half(t_lst **lsts, int size, int pivot)
{
	int	moved;
	int	bias;

	moved = N_NOMOVE;
	bias = SIZE_ZERO;
	while ((size > moved * 2 + 1 || pswp_search_min(lsts[ID_A]) <= pivot) \
		&& !(pswp_cmp_betop_a(lsts[ID_A], size, pivot, moved) \
		&& pswp_sortchk_whole(lsts[ID_A]) > 0))
	{
		if (bias <= (size - moved) / 2)
			bias = pswp_calc_bias_h(lsts[ID_A], size, pivot);
		if (pswp_sortchk_co_ss_serial(lsts))
			pswp_oper_ss(lsts);
		else if (lsts[ID_A]->prev->key <= pivot \
			&& lsts[ID_A]->prev->key < lsts[ID_A]->key)
			pswp_oper_rrx(lsts, ID_A);
		else if (lsts[ID_A]->key <= pivot)
			moved += pswp_oper_pb(lsts);
		else if (bias > (size - moved) / 2)
			pswp_oper_rrx(lsts, ID_A);
		else
			pswp_oper_rx(lsts, ID_A);
	}
	return (moved);
}

static int	pswp_div_a_whole_tri(t_lst **lsts, int size, int pivot, int pivot2)
{
	int	moved;
	int	bias;

	moved = N_NOMOVE;
	bias = SIZE_ZERO;
	while (pswp_search_min(lsts[ID_A]) <= pivot \
		|| pswp_search_le(lsts[ID_B], pivot2) < pivot - pivot2)
	{
		bias = pswp_calc_bias_2t(lsts[ID_A], size, pivot);
		if (pswp_sortchk_co_ss_serial(lsts))
			pswp_oper_ss(lsts);
		else if (pswp_cmp_dawt_prev(lsts[ID_A], pivot))
			pswp_oper_rrx(lsts, ID_A);
		else if (pswp_cmp_dawt_corx(lsts, pivot, pivot2))
			pswp_oper_corx(lsts, ID_A, pivot2 - size / 3, pivot2);
		else if (pswp_cmp_dawt_pivot2(lsts[ID_B], size, pivot2))
			pswp_oper_rx(lsts, ID_B);
		else if (lsts[ID_A]->key <= pivot)
			moved += pswp_oper_pb(lsts);
		else if (bias > (size - moved) / 2)
			pswp_oper_rrx(lsts, ID_A);
		else
			pswp_oper_rx(lsts, ID_A);
	}
	return (moved);
}

int	pswp_div_a_whole(t_lst **lsts, t_node **nodes, ssize_t idx)
{
	int	size;
	int	pivot;
	int	pivot2;

	size = nodes[idx]->size;
	if (size <= SIZE_ZERO)
		size = ft_lstsize(lsts[ID_A]);
	pivot2 = pswp_calc_pivot_t(nodes[idx]);
	if (size < SIZE_LARGE)
		pivot = pswp_calc_pivot_h(nodes[idx]);
	else
		pivot = pswp_calc_pivot_2t(nodes[idx]);
	if (SIZE_ZERO < size && size <= SIZE_CHK)
		return (pswp_sort_three(lsts, ID_A));
	else if (size <= SIZE_ZERO || pswp_search_min(lsts[ID_A]) > pivot)
		return (N_NOMOVE);
	else if (size < SIZE_LARGE)
		return (pswp_div_a_whole_half(lsts, size, pivot));
	return (pswp_div_a_whole_tri(lsts, size, pivot, pivot2));
}
