/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/31 02:20:43 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_sort(t_lst **lsts, int size)
{
	int		moved;

	lsts[ID_B] = NULL;
	if (pswp_sortchk_whole(lsts[ID_A]) > 0)
		return (N_NOMOVE);
	else if (size <= 3)
		return (pswp_sort_three(lsts, ID_A));
	if (size <= 6)
		moved = pswp_sort_le6(lsts, size);
	else
		moved = pswp_sort_gt6(lsts, size);
	while (lsts[ID_B] != NULL)
		moved += pswp_oper_pa(lsts);
	return (ERR_OK);
}
