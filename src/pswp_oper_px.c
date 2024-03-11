/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_oper_px.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/11 22:01:54 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pswp_oper_push(t_lst **src, t_lst **dst)
{
	t_lst	*tmp;

	if (src == NULL || *src == NULL)
		return ;
	tmp = NULL;
	(*src)->prev->next = (*src)->next;
	(*src)->next->prev = (*src)->prev;
	if (*src != (*src)->next)
		tmp = (*src)->next;
	if (*dst == NULL)
	{
		(*src)->prev = *src;
		(*src)->next = *src;
	}
	else
	{
		(*src)->prev = (*dst)->prev;
		(*src)->next = *dst;
		(*dst)->prev->next = *src;
		(*dst)->prev = *src;
	}
	*dst = *src;
	*src = tmp;
}

int	pswp_oper_pa(t_lst **lsts)
{
	ft_putstr_nl(STR_PA);
	pswp_oper_push(&lsts[ID_B], &lsts[ID_A]);
	return (-N_MOVE);
}

int	pswp_oper_pb(t_lst **lsts)
{
	ft_putstr_nl(STR_PB);
	pswp_oper_push(&lsts[ID_A], &lsts[ID_B]);
	return (N_MOVE);
}
