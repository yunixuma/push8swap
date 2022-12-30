/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 03:00:50 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/14 02:05:04 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lstclear(t_lst *lst)
{
	t_lst	*ele;
	t_lst	*next;

	if (lst == NULL)
		return (NULL);
	ele = lst;
	while (ele != NULL)
	{
		next = ele->next;
		free(ele);
		if (next == lst)
			ele = NULL;
		else
			ele = next;
	}
	return (NULL);
}
