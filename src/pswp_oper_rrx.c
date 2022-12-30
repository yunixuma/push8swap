/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_oper_rrx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/31 02:19:13 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pswp_oper_revrotate(t_lst **lsts, int lst_id)
{
	lsts[lst_id] = lsts[lst_id]->prev;
}

int	pswp_oper_rrr(t_lst **lsts)
{
	pswp_oper_revrotate(lsts, ID_A);
	pswp_oper_revrotate(lsts, ID_B);
	ft_putstr(STR_RRR);
	return (-N_MOVE);
}

int	pswp_oper_rrx(t_lst **lsts, int lst_id)
{
	pswp_oper_revrotate(lsts, lst_id);
	if (lst_id == ID_A)
		ft_putstr(STR_RRA);
	else
		ft_putstr(STR_RRB);
	return (-N_MOVE);
}

int	pswp_oper_corrx(t_lst **lsts, int lst_id, int lower, int upper)
{
	if (lst_id == ID_A)
	{
		if (lsts[ID_B] == NULL || lsts[ID_B]->prev->key < lsts[ID_B]->key \
			|| !ft_inrange(lsts[ID_B]->prev->key, lower, upper))
			pswp_oper_rrx(lsts, ID_A);
		else
			pswp_oper_rrr(lsts);
	}
	else if (lst_id == ID_B)
	{
		if (lsts[ID_A] == NULL || lsts[ID_A]->prev->key > lsts[ID_A]->key \
			|| !ft_inrange(lsts[ID_A]->prev->key, lower, upper))
			pswp_oper_rrx(lsts, ID_B);
		else
			pswp_oper_rrr(lsts);
	}
	return (-N_MOVE);
}
