/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/12 18:43:32 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_FUNC_BONUS_H
# define PUSH_SWAP_FUNC_BONUS_H

// # include <stdio.h>
# include "get_next_line.h"

int		pswp_sort(t_lst **lsts, int status);
int		pswp_sort_input(t_lst **lsts);
void	pswp_oper_sx(t_lst **lsts, int lst_id);
void	pswp_oper_ss(t_lst **lsts);
// void	pswp_oper_cosx(t_lst **lsts, int lst_id);
int		pswp_oper_pa(t_lst **lsts);
int		pswp_oper_pb(t_lst **lsts);
int		pswp_oper_rx(t_lst **lsts, int lst_id);
int		pswp_oper_rr(t_lst **lsts);
// int		pswp_oper_corx(t_lst **lsts, int lst_id, int lower, int upper);
int		pswp_oper_rrx(t_lst **lsts, int lst_id);
int		pswp_oper_rrr(t_lst **lsts);
// int		pswp_oper_corrx(t_lst **lsts, int lst_id, int lower, int upper);
int		pswp_print_err(int status);
int		pswp_print_oper(const char *s);
// int		ft_lstsize(t_lst *lst);
// int		ft_hasflag(int val, int flag);
char	**ft_split(char const *s, char c);
char	**ft_split_free(char **arr, size_t n);
// void	ft_swap_int(int *m, int *n);
// int		ft_putstr(const char *s);
// char	*get_next_line(int fd);

#endif
