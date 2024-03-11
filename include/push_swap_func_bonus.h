/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/11 23:42:31 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_FUNC_BONUS_H
# define PUSH_SWAP_FUNC_BONUS_H

# include <stdio.h>

int		pswp_argchk(char **args);
char	**pswp_arg2arr(int argc, char *argv[]);
t_lst	*pswp_stackinit(char **args);
int		pswp_sort(t_lst **lsts, int status);
int		pswp_sort_input(t_lst **lsts);
int		pswp_sortchk_whole(t_lst *lst);
void	pswp_oper_sx(t_lst **lsts, int lst_id);
void	pswp_oper_ss(t_lst **lsts);
void	pswp_oper_cosx(t_lst **lsts, int lst_id);
int		pswp_oper_pa(t_lst **lsts);
int		pswp_oper_pb(t_lst **lsts);
int		pswp_oper_rx(t_lst **lsts, int lst_id);
int		pswp_oper_rr(t_lst **lsts);
int		pswp_oper_corx(t_lst **lsts, int lst_id, int lower, int upper);
int		pswp_oper_rrx(t_lst **lsts, int lst_id);
int		pswp_oper_rrr(t_lst **lsts);
int		pswp_oper_corrx(t_lst **lsts, int lst_id, int lower, int upper);
int		pswp_printerr(int status);
t_lst	*pswp_lstnew(int num);
void	pswp_lstadd_next(t_lst *last, t_lst *new);
void	pswp_lstclear(t_lst **lsts);
t_lst	*ft_lstclear(t_lst *lst);
int		ft_lstsize(t_lst *lst);
int		ft_hasflag(int val, int flag);
char	**ft_split(char const *s, char c);
char	**ft_split_free(char **arr, size_t n);
void	ft_swap_int(int *m, int *n);
int		ft_putstr(const char *s);
int		ft_putstr_nl(const char *s);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_inrange(int nb, int left, int right);
size_t	ft_strlen(const char *str);

#endif
