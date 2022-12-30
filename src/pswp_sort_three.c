/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_sort_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/27 22:20:33 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_sort_three(t_lst **lsts, int lst_id)
{
	int	flag;

	while (pswp_sortchk_whole(lsts[lst_id]) <= 0)
	{
		flag = pswp_sortchk_three(lsts[lst_id]);
		if (ft_hasflag(flag, FLAG_SX))
			pswp_oper_sx(lsts, lst_id);
		else if (ft_hasflag(flag, FLAG_RX))
			pswp_oper_rx(lsts, lst_id);
		else if (ft_hasflag(flag, FLAG_RRX))
			pswp_oper_rrx(lsts, lst_id);
	}
	return (N_NOMOVE);
}
