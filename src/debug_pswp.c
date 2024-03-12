/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_pswp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/30 13:45:11 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pswp_debug_print_lst(t_lst *lst, int lst_id)
{
	t_lst	*ele;
	int		i;
	int		size;

	size = ft_lstsize(lst);
	ele = lst;
	dprintf(FD_DEBUG, "[%d]\t%%p: %p\tsize: %3d\n", lst_id, ele, size);
	i = INDEX_LIST;
	while (ele != NULL && i < size)
	{
		dprintf(FD_DEBUG, "%3d\t", i);
		dprintf(FD_DEBUG, "%%p: %p\t", ele);
		dprintf(FD_DEBUG, "val: %3d\t", ele->val);
		dprintf(FD_DEBUG, "key: %3d\t", ele->key);
		dprintf(FD_DEBUG, "prev: %p\t", ele->prev);
		dprintf(FD_DEBUG, "next: %p\n", ele->next);
		ele = ele->next;
		i++;
	}
}

void	pswp_debug_print_lsts(t_lst **lsts)
{
	if (DEBUG_MODE == 0)
		return ;
	dprintf(FD_DEBUG, "lsts\t%%p: %p\n", lsts);
	pswp_debug_print_lst(lsts[ID_A], ID_A);
	pswp_debug_print_lst(lsts[ID_B], ID_B);
}

void	pswp_debug_print_nodes(t_node **nodes)
{
	ssize_t	size;
	ssize_t	i;

	if (DEBUG_MODE == 0)
		return ;
	if (nodes == NULL || nodes[0] == NULL)
		return ;
	size = 0;
	while (nodes[size] != NULL)
		size++;
	dprintf(FD_DEBUG, "nodes\t%%p: %p\tsize: %zd\n", nodes, size);
	i = 0;
	while (i < size)
	{
		dprintf(FD_DEBUG, "%3zd\t", i);
		dprintf(FD_DEBUG, "%%p: %p\t", nodes[i]);
		dprintf(FD_DEBUG, "key: %3d\t", nodes[i]->key);
		dprintf(FD_DEBUG, "size: %3d\t", nodes[i]->size);
		dprintf(FD_DEBUG, "lst: %d\t", nodes[i]->lst);
		dprintf(FD_DEBUG, "pos: %3d\t", nodes[i]->pos);
		dprintf(FD_DEBUG, "fixed: %d\n", nodes[i]->fixed);
		i++;
	}
}

void	pswp_debug_print_both(t_lst **lsts, t_node **nodes)
{
	if (DEBUG_MODE == 0)
		return ;
	pswp_debug_print_nodes(nodes);
	pswp_debug_print_lsts(lsts);
}
