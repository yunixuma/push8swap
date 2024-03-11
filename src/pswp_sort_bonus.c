/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_sort_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/12 08:23:09 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_sort(t_lst **lsts, int status)
{
	// (void)size;
	lsts[ID_B] = NULL;
	status = 0;
	while(!status)
	{
		status = pswp_sort_input(lsts);
		if (status < 0)
			return (pswp_printerr(status));
		printf("status: %d\n", status);
	}
	if (pswp_sortchk_whole(lsts[ID_A]) > 0)
		ft_putstr_nl(STR_OK);
	else
		ft_putstr_nl(STR_KO);
	// while (ft_lstsize(lsts[ID_B]) > 0)
	// 	pswp_oper_pa(lsts);
	return (ERR_OK);
}
