/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_common.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/30 13:31:11 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_COMMON_H
# define DEBUG_COMMON_H

# include <stdio.h>
# include <stdarg.h>

# define FD_DEBUG		2
# ifndef DEBUG_MODE
#  define DEBUG_MODE	0
#  define debug_printf(...) debug_dummy(__VA_ARGS__)
# else
#  define debug_printf(...) dprintf(FD_DEBUG, __VA_ARGS__)
# endif

int		debug_dummy(const char *format, ...);

#endif
