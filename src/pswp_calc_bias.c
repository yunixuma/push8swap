/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_calc_bias.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/31 02:56:49 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_calc_bias_h(t_lst *lst, int size, int pivot)
{
	return (pswp_sortchk_range(lst, pivot + 1, pivot + (size + 1) / 2));
}

int	pswp_calc_bias_2t(t_lst *lst, int size, int pivot)
{
	return (pswp_sortchk_range(lst, pivot + 1, pivot + (size + 2) / 3));
}
