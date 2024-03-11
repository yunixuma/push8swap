/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_sort_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/12 08:33:43 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswp_sort_input(t_lst **lsts)
{
	char	buf[BUF_SIZE];
	int		len_read;
(void)lsts;
	len_read = read(FD_INPUT, buf, BUF_SIZE);
	// if (len_read < 0)
		return (len_read);
	if (*(buf + len_read - 1) != CHR_NL)
		return (EOF);
	// write(FD_PRINT, buf, len_read);
	// printf("%d {", len_read);
	// int i = 0;
	// while (i < len_read)
	// {
	// 	printf("%02x", buf[i]);
	// 	fflush(stdout);
	// 	i++;
	// }
	// printf("}\n");
	return (ERR_NOERR);
}
