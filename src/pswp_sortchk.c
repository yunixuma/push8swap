/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_sortchk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/28 14:51:33 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_sortchk_whole(t_lst *lst)
{
	t_lst	*ele;
	int		direction;

	if (lst == NULL)
		return (FLAG_EMPTY);
	ele = lst->next;
	if (ele == lst || ele == NULL)
		return (FLAG_SINGLE);
	if (lst->key < ele->key)
		direction = 1;
	else
		direction = -1;
	while (ele->next != lst)
	{
		if (direction == 1 && ele->key > ele->next->key)
			return (FLAG_INVAL);
		else if (direction == -1 && ele->key < ele->next->key)
			return (FLAG_INVAL);
		ele = ele->next;
	}
	return (direction * FLAG_ASC);
}

int	pswp_sortchk_part(t_lst *lst, int size, int offset)
{
	t_lst	*ele;
	int		direction;

	if (size <= SIZE_ZERO || lst == NULL)
		return (FLAG_EMPTY);
	ele = lst;
	while (offset-- > 0)
	{
		if (ele->next == NULL || ele->next == lst)
			return (FLAG_EMPTY);
		ele = ele->next;
	}
	if (size == 1 || ele->next == NULL || ele->next == lst)
		return (FLAG_SINGLE);
	direction = (ele->key < ele->next->key) * 2 - 1;
	while (size-- > 0 && ele->next != lst)
	{
		if ((direction == 1 && ele->key > ele->next->key) \
			|| (direction == -1 && ele->key < ele->next->key))
			return (FLAG_INVAL);
		ele = ele->next;
	}
	return (direction * FLAG_ASC);
}
