/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_div_a_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/31 00:48:58 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_div_a_top_half(t_lst **lsts, int size, int pivot)
{
	int	moved;
	int	rotated;
// dprintf(STDERR_FILENO, "%s:%d pivot: %d\n", __FILE__, __LINE__, pivot);
	if (size < 1 || pswp_search_min(lsts[ID_A]) > pivot)
		return (N_NOMOVE);
	moved = N_NOMOVE;
	rotated = N_NOMOVE;
	while (moved + rotated < size)
	{
		if (pswp_sortchk_co_ss_serial(lsts))
			pswp_oper_ss(lsts);
		else if (lsts[ID_A]->key <= pivot)
			moved += pswp_oper_pb(lsts);
		else
			rotated += pswp_oper_rx(lsts, ID_A);
	}
	return (moved);
}

int	pswp_div_a_top(t_lst **lsts, t_node **nodes, ssize_t idx)
{
	int	size;
	int	pivot;
// dprintf(STDERR_FILENO, "%s:%d idx: %ld\n", __FILE__, __LINE__, idx);

	size = nodes[idx]->size;
	if (size <= SIZE_ZERO)
		size = ft_lstsize(lsts[ID_A]);
	pivot = pswp_calc_pivot_h(nodes[idx]);
	if (SIZE_ZERO < size && size <= SIZE_CHK)
		return (pswp_sort_three_a_top(lsts));
	else if (size <= SIZE_ZERO || pswp_search_min(lsts[ID_A]) > pivot)
		return (N_NOMOVE);
	return (pswp_div_a_top_half(lsts, size, pivot));
}
