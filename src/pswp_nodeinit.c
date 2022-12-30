/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_nodeinit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/27 02:20:19 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	**pswp_nodeinit(int size)
{
	t_node	**nodes;

	nodes = (t_node **)malloc((size / 2 + 1) * sizeof(t_node *));
	if (nodes == NULL)
		return (NULL);
	nodes[0] = (t_node *)malloc(sizeof(t_node));
	if (nodes[0] == NULL)
	{
		free(nodes);
		return (NULL);
	}
	nodes[0]->key = KEY_MIN;
	nodes[0]->size = size;
	nodes[0]->lst = ID_A;
	nodes[0]->pos = N_ZEROPOS;
	nodes[0]->fixed = false;
	nodes[1] = NULL;
	return (nodes);
}
