/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:19:03 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/17 20:39:40 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static ssize_t	ft_putstrn(const char *s, ssize_t len)
{
	ssize_t	ret;

	if (len < 0)
	{
		errno = EINVAL;
		return (0);
	}
	if (s == NULL)
		return (0);
	ret = 0;
	while (len > INT_MAX)
	{
		ret += write(FD_PRINT, s, INT_MAX);
		s += INT_MAX;
		len -= INT_MAX;
	}
	ret += write(FD_PRINT, s, len);
	return (ret);
}

int	ft_putstr(const char *s)
{
	ssize_t	len;

	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	if (len != ft_putstrn(s, len))
		return (ERR_WRITE);
	return (ERR_NOERR);
}

int	ft_putstr_nl(const char *s)
{
	ssize_t	status;

	status = ft_putstr(s);
	if (status == ERR_NOERR)
		status = ft_putstr(STR_NL);
	return (status);
}
