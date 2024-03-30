/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_cmp_dawt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/30 23:19:20 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_cmp_dawt_prev(t_lst *lst, int pivot)
{
	if (lst->prev->key <= pivot && lst->prev->key < lst->key)
		return (true);
	else
		return (false);
}

int	pswp_cmp_dawt_corx(t_lst **lsts, int pivot, int pivot2)
{
	if (lsts[ID_A]->key > pivot && lsts[ID_B] != NULL \
			&& pswp_search_max(lsts[ID_B]) > pivot2)
		return (true);
	else
		return (false);
}

int	pswp_cmp_dawt_pivot2(t_lst *lst, int size, int pivot2)
{
	int	lower;

	lower = pivot2 - size / 3;
	if (lst != NULL && ft_inrange(lst->key, lower, pivot2) \
			&& !pswp_search_range_only(lst, lower, pivot2))
		return (true);
	else
		return (false);
}
