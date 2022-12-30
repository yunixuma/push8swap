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

void	pswp_lstclear(t_lst **lsts)
{
	if (lsts == NULL)
		return ;
	ft_lstclear(lsts[ID_A]);
	ft_lstclear(lsts[ID_B]);
	return ;
}
