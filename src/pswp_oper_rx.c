/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_oper_rx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/12 14:55:29 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pswp_oper_rotate(t_lst **lsts, int lst_id)
{
	lsts[lst_id] = lsts[lst_id]->next;
}

int	pswp_oper_rr(t_lst **lsts)
{
	pswp_oper_rotate(lsts, ID_A);
	pswp_oper_rotate(lsts, ID_B);
	pswp_print_oper(STR_RR);
	return (N_MOVE);
}

int	pswp_oper_rx(t_lst **lsts, int lst_id)
{
	pswp_oper_rotate(lsts, lst_id);
	if (lst_id == ID_A)
		pswp_print_oper(STR_RA);
	else
		pswp_print_oper(STR_RB);
	return (N_MOVE);
}

int	pswp_oper_corx(t_lst **lsts, int lst_id, int lower, int upper)
{
	if (lst_id == ID_A)
	{
		if (lsts[ID_B] == NULL \
			|| !ft_inrange(lsts[ID_B]->key, lower, upper))
			pswp_oper_rx(lsts, ID_A);
		else
			pswp_oper_rr(lsts);
	}
	else if (lst_id == ID_B)
	{
		if (lsts[ID_A] == NULL \
			|| !ft_inrange(lsts[ID_A]->key, lower, upper))
			pswp_oper_rx(lsts, ID_B);
		else
			pswp_oper_rr(lsts);
	}
	return (N_MOVE);
}
