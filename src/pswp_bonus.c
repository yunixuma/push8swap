/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/11 20:12:09 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
__attribute__((destructor))
	static void destructor()
{
		system("leaks -q push_swap");
}
*/

int	main(int argc, char *argv[])
{
	t_lst	*lsts[N_STACKS];
	char	**args;
	int		size;

	if (argc <= INDEX_ARG)
		exit (ERR_NOERR);
	args = pswp_arg2arr(argc, argv);
	if (args == NULL || *args == NULL)
	{
		ft_split_free(args, INT_MAX);
		exit (pswp_printerr(ERR_NOARG));
	}
	size = pswp_argchk(args);
	if (size < 0)
		exit (pswp_printerr(-size));
	lsts[ID_A] = pswp_stackinit(args);
	if (argc == INDEX_ARG + 1)
		ft_split_free(args, INT_MAX);
	else
		free(args);
	if (lsts[ID_A] == NULL)
		exit (pswp_printerr(ERR_DUPL));
	pswp_sort(lsts, size);
	pswp_lstclear(lsts);
	exit (0);
}
