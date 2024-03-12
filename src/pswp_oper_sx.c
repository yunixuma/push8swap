/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_oper_sx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/12 14:55:30 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pswp_oper_swap(t_lst **lsts, int lst_id)
{
	t_lst	*tmp;

	if (lsts == NULL || lsts[lst_id] == NULL)
		return ;
	tmp = (lsts[lst_id])->next;
	if (tmp->next != lsts[lst_id])
	{
		tmp->prev = (lsts[lst_id])->prev;
		lsts[lst_id]->prev->next = tmp;
		lsts[lst_id]->prev = tmp;
		tmp->next->prev = lsts[lst_id];
		lsts[lst_id]->next = tmp->next;
		tmp->next = lsts[lst_id];
	}
	lsts[lst_id] = tmp;
}

void	pswp_oper_ss(t_lst **lsts)
{
	pswp_oper_swap(lsts, ID_A);
	pswp_oper_swap(lsts, ID_B);
	pswp_print_oper(STR_SS);
}

void	pswp_oper_sx(t_lst **lsts, int lst_id)
{
	pswp_oper_swap(lsts, lst_id);
	if (lst_id == ID_A)
		pswp_print_oper(STR_SA);
	else
		pswp_print_oper(STR_SB);
}

void	pswp_oper_cosx(t_lst **lsts, int lst_id)
{
	if (lst_id == ID_A && (lsts[ID_B] == NULL \
		|| lsts[ID_B]->key > lsts[ID_B]->next->key))
		pswp_oper_sx(lsts, ID_A);
	else if (lst_id == ID_B && (lsts[ID_A] == NULL \
		|| lsts[ID_A]->key < lsts[ID_A]->next->key))
		pswp_oper_sx(lsts, ID_B);
	else
		pswp_oper_ss(lsts);
}
