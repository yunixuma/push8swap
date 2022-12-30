/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_calc_pivot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/31 02:25:45 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_calc_pivot_h(t_node *node)
{
	if (node->size <= SIZE_CHK)
		return (node->key - 1);
	return (node->key + (node->size / 2) - 1);
}

int	pswp_calc_pivot_q(t_node *node)
{
	return (node->key + (node->size >> 2) - 1);
}

int	pswp_calc_pivot_t(t_node *node)
{
	return (node->key + node->size / 3 - 1);
}

int	pswp_calc_pivot_2t(t_node *node)
{
	int	tmp;

	tmp = node->size / 3;
	return (node->key + tmp + (node->size - tmp) / 2 - 1);
}
