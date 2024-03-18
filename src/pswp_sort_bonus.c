/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_sort_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/18 20:44:58 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_sort(t_lst **lsts, int status)
{
	lsts[ID_B] = NULL;
	status = ERR_NOERR;
	while(!status)
	{
		// pswp_debug_print_lsts(lsts);
		status = pswp_sort_input(lsts);
		if (status > 0)
			return (status);
	}
	if (pswp_sortchk_whole(lsts[ID_A]) > 0 && lsts[ID_B] == NULL)
		ft_putstr_nl(STR_OK);
	else
		ft_putstr_nl(STR_KO);
	// while (ft_lstsize(lsts[ID_B]) > 0)
	// 	pswp_oper_pa(lsts);
	return (ERR_OK);
}
