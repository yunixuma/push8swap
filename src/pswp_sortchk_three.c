/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_sortchk_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/23 03:08:44 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_sortchk_three(t_lst *lst)
{
	if (lst == NULL)
		return (FLAG_EMPTY);
	else if (lst->next == lst)
		return (FLAG_SINGLE);
	else if (lst->key > lst->next->key && lst->key > lst->prev->key)
	{
		if (lst->next->key >= lst->prev->key)
			return (FLAG_654);
		return (FLAG_645);
	}
	else if (lst->key < lst->next->key && lst->key < lst->prev->key)
	{
		if (lst->next->key <= lst->prev->key)
			return (FLAG_456);
		return (FLAG_465);
	}
	else if (lst->key < lst->prev->key)
		return (FLAG_546);
	return (FLAG_564);
}

int	pswp_sortchk_three_back(t_lst *lst)
{
	if (lst == NULL)
		return (FLAG_EMPTY);
	else if (lst->next == lst)
		return (FLAG_SINGLE);
	else if (lst->key > lst->next->key && lst->key > lst->prev->key)
	{
		if (lst->next->key >= lst->prev->key)
			return (FLAG_321);
		return (FLAG_312);
	}
	else if (lst->key < lst->next->key && lst->key < lst->prev->key)
	{
		if (lst->next->key <= lst->prev->key)
			return (FLAG_123);
		return (FLAG_132);
	}
	else if (lst->key < lst->prev->key)
		return (FLAG_213);
	return (FLAG_231);
}
