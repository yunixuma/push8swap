/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_search_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/30 17:54:21 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_search_range(t_lst *lst, int lower, int upper)
{
	t_lst	*ele;

	if (lst == NULL)
		return (false);
	if (ft_inrange(lst->key, lower, upper))
		return (true);
	ele = lst->next;
	while (ele != NULL && ele != lst)
	{
		if (ft_inrange(ele->key, lower, upper))
			return (true);
		ele = ele->next;
	}
	return (false);
}

int	pswp_search_range_only(t_lst *lst, int lower, int upper)
{
	t_lst	*ele;

	if (lst == NULL)
		return (false);
	if (!ft_inrange(lst->key, lower, upper))
		return (false);
	ele = lst->next;
	while (ele != NULL && ele != lst)
	{
		if (!ft_inrange(ele->key, lower, upper))
			return (false);
		ele = ele->next;
	}
	return (true);
}
