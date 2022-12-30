/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_search_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/27 14:47:06 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_search_min(t_lst *lst)
{
	t_lst	*ele;
	int		min;

	if (lst == NULL)
		return (INT_MAX);
	ele = lst->next;
	min = lst->key;
	while (ele != NULL && ele != lst)
	{
		if (ele->key < min)
			min = ele->key;
		ele = ele->next;
	}
	return (min);
}

int	pswp_search_min_edge(t_lst *lst)
{
	int	min;
	int	cycle;

	lst = lst->next;
	min = lst->next->key;
	cycle = SIZE_CHK * 2 - 1;
	while (cycle-- > 0)
	{
		if (lst->key < min)
			min = lst->key;
		lst = lst->prev;
	}
	return (min);
}
