/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_sort_le6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/28 14:36:00 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pswp_sort_le6_sub(t_lst **lsts, int flag_a, int flag_b)
{
	if (ft_hasflag(flag_a & flag_b, FLAG_SX))
		pswp_oper_ss(lsts);
	else if (ft_hasflag(flag_a & flag_b, FLAG_RX))
		pswp_oper_rr(lsts);
	else if (ft_hasflag(flag_a & flag_b, FLAG_RRX))
		pswp_oper_rrr(lsts);
	else if (ft_hasflag(flag_a, FLAG_SX))
		pswp_oper_sx(lsts, ID_A);
	else if (ft_hasflag(flag_b, FLAG_SX))
		pswp_oper_sx(lsts, ID_B);
	else if (ft_hasflag(flag_a, FLAG_RX))
		pswp_oper_rx(lsts, ID_A);
	else if (ft_hasflag(flag_a, FLAG_RRX))
		pswp_oper_rrx(lsts, ID_A);
	else if (ft_hasflag(flag_b, FLAG_RX))
		pswp_oper_rx(lsts, ID_B);
	else if (ft_hasflag(flag_b, FLAG_RRX))
		pswp_oper_rrx(lsts, ID_B);
}

int	pswp_sort_le6(t_lst **lsts, int size)
{
	int	flag_a;
	int	flag_b;
	int	moved;

	moved = pswp_div_a_whole_half(lsts, size, KEY_MIN + size / 2 - 1);
	flag_a = pswp_sortchk_three(lsts[ID_A]);
	flag_b = pswp_sortchk_three_back(lsts[ID_B]);
	while (flag_a != FLAG_456 || flag_b > FLAG_321)
	{
		pswp_sort_le6_sub(lsts, flag_a, flag_b);
		flag_a = pswp_sortchk_three(lsts[ID_A]);
		flag_b = pswp_sortchk_three_back(lsts[ID_B]);
	}
	return (moved);
}
