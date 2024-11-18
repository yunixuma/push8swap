/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/05/05 20:54:20 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BONUS
#  define BONUS 0
# endif

# include <unistd.h>
# include <stdlib.h>
// # include <stdio.h>
# include <limits.h>
# include <errno.h>
# include <stdbool.h>
# include "push_swap_const.h"
# include "push_swap_flag.h"
# include "push_swap_typedef.h"
# include "push_swap_func.h"

# if BONUS == 0
#  include "push_swap_func_mandatory.h"
# else
#  include "push_swap_func_bonus.h"
# endif

# ifdef DEBUG_MODE
#  include "debug_push_swap.h"
# endif

#endif
