/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_sortchk_range.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/28 14:51:21 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_sortchk_range(t_lst *lst, int low, int high)
{
	t_lst	*ele;
	int		bias;
	int		cycle;

	if (lst == NULL)
		return (SIZE_ZERO);
	if (low > high)
		ft_swap_int(&low, &high);
	if (lst->key < low || lst->key > high)
		return (SIZE_ZERO);
	bias = SIZE_ZERO + 1;
	ele = lst->next;
	cycle = high - low + 1;
	while (ele != NULL && ele != lst && cycle-- > 0)
	{
		if (ele->key < low || ele->key > high)
			return (bias);
		bias++;
		ele = ele->next;
	}
	return (bias);
}

int	pswp_sortchk_range_back(t_lst *lst, int low, int high)
{
	t_lst	*ele;
	int		bias;
	int		cycle;

	if (lst == NULL)
		return (SIZE_ZERO);
	if (low > high)
		ft_swap_int(&low, &high);
	lst = lst->prev;
	if (lst->key < low || lst->key > high)
		return (SIZE_ZERO);
	bias = SIZE_ZERO + 1;
	ele = lst->prev;
	cycle = high - low + 1;
	while (ele != NULL && ele != lst && cycle-- > 0)
	{
		if (ele->key < low || ele->key > high)
			return (bias);
		bias++;
		ele = ele->prev;
	}
	return (bias);
}
