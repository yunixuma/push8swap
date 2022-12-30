/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_argchk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/24 13:41:16 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pswp_isint(const char *str)
{
	ssize_t	len;
	int		is_minus;

	is_minus = (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0' && *(str + 1) != '\0')
		str++;
	len = 0;
	while (*(str + len) != '\0')
	{
		if (*(str + len) < '0' || '9' < *(str + len))
			return (false);
		if (len < 0 || 10 <= len)
			return (false);
		len++;
	}
	if (len == 10)
	{
		if (!is_minus && ft_strncmp(str, STR_INTMAX, len) > 0)
			return (false);
		else if (is_minus && ft_strncmp(str, STR_INTMIN, len) > 0)
			return (false);
	}
	return (len);
}

int	pswp_argchk(char **args)
{
	int	i;
	int	flag;

	flag = true;
	i = 0;
	while (args[i] != NULL && flag)
	{
		if (!pswp_isint(args[i]))
			flag = false;
		i++;
	}
	if (flag == false)
	{
		while (args[i] != NULL)
			i++;
		return (-ERR_NOTINT);
	}
	return (i);
}
