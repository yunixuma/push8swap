/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_nodeclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 03:00:50 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/28 20:06:03 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	**pswp_nodeclear(t_node **nodes)
{
	ssize_t	i;

	if (nodes == NULL)
		return (NULL);
	i = 0;
	while (nodes[i] != NULL)
	{
		free(nodes[i]);
		i++;
	}
	free(nodes);
	nodes = NULL;
	return (NULL);
}
