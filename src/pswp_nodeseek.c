/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_nodeseek.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/31 00:55:34 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	pswp_nodeseek_min(t_node **nodes)
{
	int		min;
	ssize_t	i;
	ssize_t	i_min;

	if (nodes == NULL || nodes[0] == NULL)
		return (INDEX_NONE);
	min = INT_MAX;
	i = 0;
	while (nodes[i] != NULL)
	{
		if (nodes[i]->key < min)
		{
			i_min = i;
			min = nodes[i]->key;
		}
		i++;
	}
	return (i_min);
}

ssize_t	pswp_nodeseek_todiv(t_node **nodes)
{
	int		max;
	ssize_t	i;
	ssize_t	i_max;

	if (nodes == NULL || nodes[0] == NULL)
		return (INDEX_NONE);
	i_max = pswp_nodeseek_min(nodes);
	max = nodes[i_max]->key;
	i = 0;
	while (nodes[i] != NULL)
	{
		// printf("nodes[%ld]->fixed: %d\n", i, nodes[i]->fixed);
		if (!nodes[i]->fixed && nodes[i]->key > max)
		{
			i_max = i;
			max = nodes[i]->key;
		}
		i++;
	}
	if (nodes[i_max]->fixed)
		return (INDEX_NONE);
	return (i_max);
}

int	pswp_nodeseek_top(t_node **nodes, int lst_id)
{
	ssize_t	i;
	int		top;

	if (nodes == NULL || nodes[0] == NULL)
		return (N_ZEROPOS);
	i = 0;
	top = INT_MIN;
	while (nodes[i] != NULL)
	{
		if (nodes[i]->lst == lst_id)
		{
			if (nodes[i]->pos > top)
				top = nodes[i]->pos;
		}
		i++;
	}
	if (top == INT_MIN)
		return (N_ZEROPOS);
	return (top);
}

int	pswp_nodeseek_bottom(t_node **nodes, int lst_id)
{
	ssize_t	i;
	int		bottom;

	if (nodes == NULL || nodes[0] == NULL)
		return (N_ZEROPOS);
	i = 0;
	bottom = INT_MAX;
	while (nodes[i] != NULL)
	{
		if (nodes[i]->lst == lst_id)
		{
			if (nodes[i]->pos < bottom)
				bottom = nodes[i]->pos;
		}
		i++;
	}
	if (bottom == INT_MAX)
		return (N_ZEROPOS);
	return (bottom);
}
