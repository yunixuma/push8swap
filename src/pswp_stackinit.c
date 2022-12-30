/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_stackinit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/27 22:27:51 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pswp_compress_sub(t_lst **ele, t_lst **min, int low, int cycle)
{
	int	j;

	j = 0;
	while (j++ < cycle)
	{
		if ((*ele)->val >= low)
		{
			if (*min == NULL || (*ele)->val < (*min)->val)
				*min = *ele;
			else if ((*ele)->val == (*min)->val)
			{
				*min = NULL;
				return ;
			}
		}
		*ele = (*ele)->next;
	}
}

static int	pswp_compress(t_lst *lst, int cycle)
{
	t_lst	*ele;
	t_lst	*ele_min;
	int		key;
	int		low;
	int		i;

	key = KEY_MIN;
	low = INT_MIN;
	i = 0;
	while (i++ < cycle)
	{
		ele = lst;
		ele_min = NULL;
		pswp_compress_sub(&ele, &ele_min, low, cycle);
		if (ele_min == NULL)
			return (ERR_DUPL);
		ele_min->key = key++;
		low = ele_min->val + 1;
	}
	return (ERR_NOERR);
}

t_lst	*pswp_stackinit(char **args)
{
	t_lst	*lst;
	t_lst	*last;
	t_lst	*new;
	int		i;

	lst = NULL;
	last = NULL;
	i = 0;
	while (errno == 0 && args[i] != NULL)
	{
		new = pswp_lstnew(ft_atoi(args[i]));
		if (new == NULL)
			return (ft_lstclear(lst));
		if (lst == NULL)
			lst = new;
		else
			pswp_lstadd_next(last, new);
		last = new;
		i++;
	}
	if (pswp_compress(lst, i))
		return (ft_lstclear(lst));
	last->next = lst;
	lst->prev = last;
	return (lst);
}
