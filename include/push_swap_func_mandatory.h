/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func_mandatory.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/05/05 19:13:17 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_FUNC_MANDATORY_H
# define PUSH_SWAP_FUNC_MANDATORY_H

int		pswp_sort(t_lst **lsts, int size);
int		pswp_sort_three(t_lst **lsts, int lst_id);
int		pswp_sort_three_a_top(t_lst **lsts);
int		pswp_sort_three_a_bottom(t_lst **lsts, int pivot);
int		pswp_sort_three_b(t_lst **lsts);
int		pswp_sort_three_b_top(t_lst **lsts, int pivot);
int		pswp_sort_three_b_bottom(t_lst **lsts, int pivot);
int		pswp_sort_le6(t_lst **lsts, int size);
int		pswp_sort_gt6(t_lst **lsts, int size);
t_node	**pswp_nodeinit(int size);
void	pswp_nodenew_a_half(t_node **nodes, ssize_t i_org, ssize_t i_new);
void	pswp_nodenew_a_tri(t_node **nodes, ssize_t i_org, ssize_t i_new);
void	pswp_nodenew_a_tri2(t_node **nodes, ssize_t i_org, ssize_t i_new);
void	pswp_nodenew_b_half(t_node **nodes, ssize_t i_org, ssize_t i_new);
void	pswp_nodenew_b_tri(t_node **nodes, ssize_t i_org, ssize_t i_new);
void	pswp_nodenew_b_tri2(t_node **nodes, ssize_t i_org, ssize_t i_new);
t_node	*pswp_nodenew_set(int key, int size, int lst_id, int pos);
t_node	**pswp_nodeclear(t_node **nodes);
void	pswp_nodeupd_div_a(t_node **nodes, ssize_t i_org, \
	int (*pf)(t_lst **, t_node **, ssize_t));
void	pswp_nodeupd_div_b(t_node **nodes, ssize_t i_org, \
	int (*pf)(t_lst **, t_node **, ssize_t));
void	pswp_nodeupd_fix(t_node **nodes, ssize_t i_org);
ssize_t	pswp_nodeseek_min(t_node **nodes);
ssize_t	pswp_nodeseek_todiv(t_node **nodes);
int		pswp_nodeseek_top(t_node **nodes, int lst_id);
int		pswp_nodeseek_bottom(t_node **nodes, int lst_id);
int		pswp_div_a_whole(t_lst **lsts, t_node **nodes, ssize_t idx);
int		pswp_div_a_whole_half(t_lst **lsts, int size, int pivot);
int		pswp_div_a_top(t_lst **lsts, t_node **nodes, ssize_t idx);
int		pswp_div_a_bottom(t_lst **lsts, t_node **nodes, ssize_t idx);
int		pswp_div_b_whole(t_lst **lsts, t_node **nodes, ssize_t idx);
int		pswp_div_b_top(t_lst **lsts, t_node **nodes, ssize_t idx);
int		pswp_div_b_bottom(t_lst **lsts, t_node **nodes, ssize_t idx);
int		pswp_sortchk_part(t_lst *lst, int size, int offset);
int		pswp_sortchk_range(t_lst *lst, int low, int high);
int		pswp_sortchk_range_back(t_lst *lst, int low, int high);
int		pswp_sortchk_three(t_lst *lst);
int		pswp_sortchk_three_back(t_lst *lst);
int		pswp_sortchk_co_ss(t_lst **lsts);
int		pswp_sortchk_co_ss_serial(t_lst **lsts);
int		pswp_cmp_half(t_lst *ele, int size);
int		pswp_cmp_betop_a(t_lst *ele, int size, int pivot, int moved);
int		pswp_cmp_betop_b(t_lst *ele, int size, int pivot, int moved);
int		pswp_cmp_dawt_prev(t_lst *lst, int pivot);
int		pswp_cmp_dawt_corx(t_lst **lsts, int pivot, int pivot2);
int		pswp_cmp_dawt_pivot2(t_lst *lst, int size, int pivot2);
int		pswp_calc_pivot_h(t_node *node);
int		pswp_calc_pivot_q(t_node *node);
int		pswp_calc_pivot_t(t_node *node);
int		pswp_calc_pivot_2t(t_node *node);
int		pswp_calc_size_h(t_node *node);
int		pswp_calc_size_t(t_node *node);
int		pswp_calc_size_2t(t_node *node);
int		pswp_calc_bias_h(t_lst *lst, int size, int pivot);
int		pswp_calc_bias_2t(t_lst *lst, int size, int pivot);
int		pswp_search_key(t_lst *lst, int key);
int		pswp_search_min(t_lst *lst);
int		pswp_search_min_edge(t_lst *lst);
int		pswp_search_max(t_lst *lst);
int		pswp_search_max_edge(t_lst *lst);
int		pswp_search_le(t_lst *lst, int key);
int		pswp_search_le_back(t_lst *lst, int key);
int		pswp_search_gt(t_lst *lst, int key);
int		pswp_search_gt_back(t_lst *lst, int key);
int		pswp_search_range(t_lst *lst, int lower, int upper);
int		pswp_search_range_only(t_lst *lst, int lower, int upper);
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
int		ft_lstsize(t_lst *lst);
int		ft_hasflag(int val, int flag);
char	**ft_split(char const *s, char c);
char	**ft_split_free(char **arr, size_t n);
void	ft_swap_int(int *m, int *n);
int		ft_putstr_fd(const char *s, int fd);

#endif
