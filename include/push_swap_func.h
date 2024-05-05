/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/05/05 20:53:47 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_FUNC_H
# define PUSH_SWAP_FUNC_H

int		pswp_argchk(char **args);
char	**pswp_arg2arr(int argc, char *argv[]);
t_lst	*pswp_stackinit(char **args);
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
int		pswp_print_err(int status);
int		pswp_print_oper(const char *s);
t_lst	*pswp_lstnew(int num);
void	pswp_lstadd_next(t_lst *last, t_lst *new);
void	pswp_lstclear(t_lst **lsts);
t_lst	*ft_lstclear(t_lst *lst);
int		ft_putstr_nl_fd(const char *s, int fd);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_inrange(int nb, int left, int right);
size_t	ft_strlen(const char *str);

#endif
