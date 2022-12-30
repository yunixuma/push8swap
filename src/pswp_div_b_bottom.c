/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_div_b_bottom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/31 02:15:38 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pswp_div_b_bottom_half(t_lst **lsts, int size, int pivot)
{
	int	moved;

	moved = N_NOMOVE;
	while (pswp_search_max(lsts[ID_B]) > pivot \
		|| ft_inrange(lsts[ID_B]->prev->key, \
			pivot - size / 2 + 1, pivot + (size + 1) / 2))
	{
		if (pswp_sortchk_co_ss_serial(lsts))
			pswp_oper_ss(lsts);
		else if (lsts[ID_B]->key > pivot \
			&& lsts[ID_B]->key > lsts[ID_B]->prev->key)
			moved += pswp_oper_pa(lsts);
		else if (lsts[ID_B]->prev->key > lsts[ID_B]->key \
			&& lsts[ID_B]->prev->key > pivot)
			pswp_oper_rrx(lsts, ID_B);
		else if (ft_inrange(pswp_search_gt(lsts[ID_B], pivot), SIZE_ZERO, size))
			pswp_oper_rx(lsts, ID_B);
		else if (lsts[ID_B]->key > pivot)
			moved += pswp_oper_pa(lsts);
		else
			pswp_oper_rrx(lsts, ID_B);
	}
	return (moved);
}

int	pswp_div_b_bottom(t_lst **lsts, t_node **nodes, ssize_t idx)
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
		return (pswp_sort_three_b_bottom(lsts, pivot));
	return (pswp_div_b_bottom_half(lsts, size, pivot));
}
