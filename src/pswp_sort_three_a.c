/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_sort_three_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/30 21:21:38 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_sort_three_a_top(t_lst **lsts)
{
	while (pswp_sortchk_part(lsts[ID_A], 3, 0) <= 0)
	{
		if (lsts[ID_A]->key > lsts[ID_A]->next->key)
			pswp_oper_cosx(lsts, ID_A);
		else
		{
			pswp_oper_rx(lsts, ID_A);
			pswp_oper_cosx(lsts, ID_A);
			pswp_oper_rrx(lsts, ID_A);
		}
	}
	return (N_NOMOVE);
}

int	pswp_sort_three_a_bottom(t_lst **lsts, int pivot)
{
	int	moved;

	moved = N_NOMOVE;
	while (pswp_sortchk_part(lsts[ID_A], SIZE_CHK, SIZE_ZERO) <= FLAG_INVAL \
		|| pswp_sortchk_range_back(lsts[ID_A], pivot + 1, pivot + SIZE_CHK) \
		> SIZE_ZERO || moved > N_NOMOVE)
	{
		if (lsts[ID_A]->key == pivot + 1)
			moved += pswp_oper_pb(lsts);
		else if (lsts[ID_A]->key > lsts[ID_A]->next->key)
			pswp_oper_cosx(lsts, ID_A);
		if (ft_inrange(lsts[ID_A]->prev->key, pivot + 1, pivot + SIZE_CHK))
			pswp_oper_rrx(lsts, ID_A);
		else if (moved > 0 && lsts[ID_A]->key < lsts[ID_A]->next->key)
			moved += pswp_oper_pa(lsts);
		else
			pswp_oper_rx(lsts, ID_A);
	}
	while (moved > 0)
		moved += pswp_oper_pa(lsts);
	return (moved);
}
