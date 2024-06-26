/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_const.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2024/03/12 18:20:35 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CONST_H
# define PUSH_SWAP_CONST_H

# define INDEX_ARG		1
# define INDEX_LIST		0
# define INDEX_NONE		-1
# define FD_INPUT		STDIN_FILENO
# define FD_PRINT		STDOUT_FILENO
# define FD_ERROR		STDERR_FILENO
# define ERR_OK			0
# define ERR_NOERR		0
# define ERR_NOTINT		EDOM
# define ERR_NOARG		EINVAL
# define ERR_INPUT		EINVAL
# define ERR_WRITE		EIO
# define ERR_READ		EIO
# define ERR_DUPL		EEXIST
# define ERR_FAIL		ENOMEM
# define ID_A			1
# define ID_B			2
# define N_MOVE			1
# define N_NOMOVE		0
# define N_ZEROPOS		0
# define N_STACKS		3
# define KEY_MIN		0
# define SIZE_ZERO		0
# define SIZE_CHK		3
# define SIZE_LARGE		100
# define BUF_SIZE		4
# define CHR_NUL		'\0'
# define CHR_DELIM		' '
# define CHR_NL			'\n'
# define STR_NL			"\n"
# define STR_SA			"sa"
# define STR_SB			"sb"
# define STR_SS			"ss"
# define STR_PA			"pa"
# define STR_PB			"pb"
# define STR_RA			"ra"
# define STR_RB			"rb"
# define STR_RR			"rr"
# define STR_RRA		"rra"
# define STR_RRB		"rrb"
# define STR_RRR		"rrr"
# define STR_OK			"OK"
# define STR_KO			"KO"
# define STR_ERR		"Error"
# define STR_NOTERR		""
# define STR_INTMAX		"2147483647"
# define STR_INTMIN		"2147483648"

#endif
