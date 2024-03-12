/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_sort_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/12 15:03:32 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pswp_sort_input_oper(t_lst **lsts, char buf[BUF_SIZE])
{
	// printf("%02x%02x%02x%02x\n", buf[0], buf[1], buf[2], buf[3]);
	if (ft_strncmp(buf, STR_SA, BUF_SIZE) == 0)
		pswp_oper_sx(lsts, ID_A);
	else if (ft_strncmp(buf, STR_SB, BUF_SIZE) == 0)
		pswp_oper_sx(lsts, ID_B);
	else if (ft_strncmp(buf, STR_SS, BUF_SIZE) == 0)
		pswp_oper_ss(lsts);
	else if (ft_strncmp(buf, STR_PA, BUF_SIZE) == 0)
		pswp_oper_pa(lsts);
	else if (ft_strncmp(buf, STR_PB, BUF_SIZE) == 0)
		pswp_oper_pb(lsts);
	else if (ft_strncmp(buf, STR_RA, BUF_SIZE) == 0)
		pswp_oper_rx(lsts, ID_A);
	else if (ft_strncmp(buf, STR_RB, BUF_SIZE) == 0)
		pswp_oper_rx(lsts, ID_B);
	else if (ft_strncmp(buf, STR_RR, BUF_SIZE) == 0)
		pswp_oper_rr(lsts);
	else if (ft_strncmp(buf, STR_RRA, BUF_SIZE) == 0)
		pswp_oper_rrx(lsts, ID_A);
	else if (ft_strncmp(buf, STR_RRB, BUF_SIZE) == 0)
		pswp_oper_rrx(lsts, ID_B);
	else if (ft_strncmp(buf, STR_RRR, BUF_SIZE) == 0)
		pswp_oper_rrr(lsts);
	else
		return (ERR_INPUT);
	return (ERR_NOERR);
}
/*
static int	pswp_sort_input_oper(t_lst **lsts, int flag)
{
	if (ft_hasflag(flag, FLAG_SX & ID_A & ID_B))
		pswp_oper_ss(lsts);
	if (ft_hasflag(flag, FLAG_RX & ID_A & ID_B))
		pswp_oper_rr(lsts);
	if (ft_hasflag(flag, FLAG_RRX & ID_A & ID_B))
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
*/
int	pswp_sort_input(t_lst **lsts)
{
	char		buf[BUF_SIZE];
	int			len_read;
	// int			flag_oper;
	static int	prev_status = ERR_NOERR;

	len_read = read(FD_INPUT, buf, BUF_SIZE);
	if (len_read < 0)
		return (pswp_print_err(ERR_READ));
	else if (len_read == 0)
	{
		if (prev_status == ERR_INPUT)
			return (pswp_print_err(ERR_INPUT));
		return (-ERR_READ);
	}
	else if (*(buf + len_read - 1) != CHR_NL)
		prev_status = ERR_INPUT;
	if (prev_status == ERR_INPUT)
		return (ERR_INPUT);
	*(buf + len_read - 1) = CHR_NUL;
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
	// flag_oper = pswp_sort_input_classify(lsts, buf);
	// if (pswp_sort_input_oper(lsts, flag_oper))
	// 	return (pswp_print_err(ERR_INPUT));
	if (pswp_sort_input_oper(lsts, buf))
		return (pswp_print_err(ERR_INPUT));
	return (ERR_NOERR);
}
