/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:08:30 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/24 00:46:22 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*pswp_lstnew(int num)
{
	t_lst	*lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	if (lst == NULL)
		return (NULL);
	lst->val = num;
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}
