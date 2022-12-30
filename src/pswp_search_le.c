/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_search_le.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/27 15:10:51 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_search_le(t_lst *lst, int key)
{
	t_lst	*ele;
	int		idx;

	if (lst == NULL)
		return (INT_MAX);
	if (lst->key <= key)
		return (INDEX_LIST);
	ele = lst->next;
	idx = INDEX_LIST + 1;
	while (ele != NULL && ele != lst)
	{
		if (ele->key <= key)
			return (idx);
		ele = ele->next;
		idx++;
	}
	return (INDEX_NONE);
}

int	pswp_search_le_back(t_lst *lst, int key)
{
	t_lst	*ele;
	int		idx;

	if (lst == NULL)
		return (INT_MAX);
	idx = ft_lstsize(lst) - 1;
	if (lst->prev->key <= key)
		return (idx);
	ele = lst->prev;
	while (ele != NULL && ele != lst)
	{
		idx--;
		if (ele->key <= key)
			return (idx);
		ele = ele->prev;
	}
	return (INDEX_NONE);
}
