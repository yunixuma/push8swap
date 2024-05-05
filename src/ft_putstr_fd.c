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

static ssize_t	ft_putstrn_fd(const char *s, ssize_t len, int fd)
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
		ret += write(fd, s, INT_MAX);
		s += INT_MAX;
		len -= INT_MAX;
	}
	ret += write(fd, s, len);
	return (ret);
}

int	ft_putstr_fd(const char *s, int fd)
{
	ssize_t	len;

	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	if (len != ft_putstrn_fd(s, len, fd))
		return (ERR_WRITE);
	return (ERR_NOERR);
}

int	ft_putstr_nl_fd(const char *s, int fd)
{
	ssize_t	status;

	status = ft_putstr_fd(s, fd);
	if (status == ERR_NOERR)
		ft_putstr_fd(STR_NL, fd);
	return (status);
}
