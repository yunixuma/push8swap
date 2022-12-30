/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_sort_three_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/31 02:25:24 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_sort_three_b(t_lst **lsts)
{
	int	moved;

	moved = N_NOMOVE;
	while (lsts != NULL && (lsts[ID_B] != NULL \
		|| pswp_sortchk_part(lsts[ID_A], SIZE_CHK, SIZE_ZERO) <= FLAG_INVAL))
	{
		if (lsts[ID_B]->key >= lsts[ID_B]->next->key \
			&& lsts[ID_B]->key >= lsts[ID_B]->prev->key)
			moved += pswp_oper_pa(lsts);
		else if (lsts[ID_B]->next->key < lsts[ID_B]->prev->key)
			pswp_oper_rrx(lsts, ID_B);
		else
			pswp_oper_sx(lsts, ID_B);
	}
	return (moved);
}

int	pswp_sort_three_b_top(t_lst **lsts, int pivot)
{
	int	moved;

	moved = N_NOMOVE;
	while (lsts != NULL && lsts[ID_B] != NULL \
		&& pswp_search_max_edge(lsts[ID_B]) > pivot \
		&& lsts[ID_A]->key > pivot + 1)
	{
		if (lsts[ID_B]->prev->key > lsts[ID_B]->key)
			pswp_oper_rrx(lsts, ID_B);
		else if (lsts[ID_B]->key < lsts[ID_B]->next->key)
			pswp_oper_cosx(lsts, ID_B);
		else if (lsts[ID_A]->key > lsts[ID_A]->next->key)
			pswp_oper_cosx(lsts, ID_A);
		else if (lsts[ID_B]->key > pivot)
			moved += pswp_oper_pa(lsts);
	}
	return (moved);
}

int	pswp_sort_three_b_bottom(t_lst **lsts, int pivot)
{
	int	moved;

	moved = N_NOMOVE;
	while (lsts != NULL && lsts[ID_B] != NULL \
		&& pswp_search_max_edge(lsts[ID_B]) >= pivot \
		&& lsts[ID_A]->key > pivot + 1)
	{
		if (lsts[ID_B]->prev->key > lsts[ID_B]->key)
			pswp_oper_rrx(lsts, ID_B);
		else if (lsts[ID_B]->key < lsts[ID_B]->next->key)
			pswp_oper_cosx(lsts, ID_B);
		else if (lsts[ID_A]->key > lsts[ID_A]->next->key)
			pswp_oper_cosx(lsts, ID_A);
		else
			moved += pswp_oper_pa(lsts);
	}
	return (moved);
}
