/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_print_oper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/31 00:55:48 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_print_oper(const char *s)
{
	// static int	limit = 150;
// 	if (limit)
// 	{
// dprintf(STDERR_FILENO, "%s:%d limit: %d\n", __FILE__, __LINE__, limit);
// 		limit--;
	return (ft_putstr_nl_fd(s, FD_PRINT));
	// }
	// return (0);
}
