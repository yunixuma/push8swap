/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/24 15:08:22 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_cmp_half(t_lst *ele, int size)
{
	if (ele->key > KEY_MIN + size / 2 - 1)
		return (true);
	return (false);
}

int	pswp_cmp_betop_a(t_lst *ele, int size, int pivot, int moved)
{
	if (ele->key == pivot + 1 - size / 2 + moved)
		return (true);
	return (false);
}

int	pswp_cmp_betop_b(t_lst *ele, int size, int pivot, int moved)
{
	if (ele->key == pivot + (size + 1) / 2 - moved)
		return (true);
	return (false);
}
