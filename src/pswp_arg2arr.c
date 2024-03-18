/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_arg2arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/18 15:16:34 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**pswp_arg2arr(int argc, char *argv[])
{
	char	**args;
	int		size;
	int		i;

	size = argc - INDEX_ARG;
	if (size == 1)
		return (ft_split(argv[INDEX_ARG], CHR_DELIM));
	args = (char **)malloc((size + 1) * sizeof(char **));
	if (args == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		args[i] = argv[INDEX_ARG + i];
		i++;
	}
	args[i] = NULL;
	return (args);
}
