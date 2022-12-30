/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_search_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/31 04:00:03 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_search_max(t_lst *lst)
{
	t_lst	*ele;
	int		max;

	if (lst == NULL)
		return (INT_MIN);
	ele = lst->next;
	max = lst->key;
	while (ele != NULL && ele != lst)
	{
		if (ele->key > max)
			max = ele->key;
		ele = ele->next;
	}
	return (max);
}

int	pswp_search_max_edge(t_lst *lst)
{
	int	max;
	int	cycle;

	lst = lst->next;
	max = lst->next->key;
	cycle = SIZE_CHK * 2 - 1;
	while (cycle-- > 0)
	{
		if (lst->key > max)
			max = lst->key;
		lst = lst->prev;
	}
	return (max);
}
