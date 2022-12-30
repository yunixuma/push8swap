/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inrange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:20:20 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/30 15:20:12 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_inrange(int nb, int lower, int upper)
{
	if (lower > upper)
		return (!ft_inrange(nb, upper + 1, lower - 1));
	return (lower <= nb && nb <= upper);
}
