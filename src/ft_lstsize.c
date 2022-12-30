/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:26:30 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/28 03:03:40 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_lst *lst)
{
	t_lst	*ele;
	int		size;

	if (lst == NULL)
		return (0);
	ele = lst->next;
	size = 1;
	while (ele != NULL && ele != lst)
	{
		ele = ele->next;
		size++;
	}
	return (size);
}
