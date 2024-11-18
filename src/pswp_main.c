/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/11/19 07:06:09 by ykosaka          ###   ########.fr       */
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

static void	pswp_freeargs(int argc, char **args)
{
	if (argc == INDEX_ARG + 1)
		ft_split_free(args, INT_MAX);
	else
		free(args);
}

int	main(int argc, char *argv[])
{
	t_lst	*lsts[N_STACKS];
	char	**args;
	int		size;

	if (argc <= INDEX_ARG)
		exit (ERR_NOERR);
	args = pswp_arg2arr(argc, argv);
	if (args == NULL || *args == NULL)
		exit (pswp_print_err(ERR_NOARG));
	size = pswp_argchk(args);
	if (size < 0) {
		pswp_freeargs(argc, args);
		exit (pswp_print_err(-size));
	}
	lsts[ID_A] = pswp_stackinit(args);
	pswp_freeargs(argc, args);
	if (lsts[ID_A] == NULL)
		exit (pswp_print_err(ERR_DUPL));
	pswp_sort(lsts, size);
	pswp_lstclear(lsts);
	exit (0);
}
