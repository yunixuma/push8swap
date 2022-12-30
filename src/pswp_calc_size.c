/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_calc_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/31 02:13:07 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_calc_size_h(t_node *node)
{
	return ((node->size + 1) / 2);
}

int	pswp_calc_size_t(t_node *node)
{
	return ((node->size + 1) / 3);
}

int	pswp_calc_size_2t(t_node *node)
{
	return ((node->size + 2) / 3);
}
