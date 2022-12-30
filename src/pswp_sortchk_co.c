/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_sortchk_co.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/30 03:05:20 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_sortchk_co_ss(t_lst **lsts)
{
	if (!lsts || !lsts[ID_A] || !lsts[ID_B])
		return (false);
	if (lsts[ID_A]->key < lsts[ID_A]->next->key \
		&& lsts[ID_B]->key > lsts[ID_B]->next->key)
		return (true);
	return (false);
}

int	pswp_sortchk_co_ss_serial(t_lst **lsts)
{
	if (!lsts || !lsts[ID_A] || !lsts[ID_B])
		return (false);
	if (lsts[ID_A]->key - 1 == lsts[ID_A]->next->key \
		&& lsts[ID_B]->key + 1 == lsts[ID_B]->next->key)
		return (true);
	return (false);
}
