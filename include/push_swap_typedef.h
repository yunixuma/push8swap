/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_typedef.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/10/26 15:31:30 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_TYPEDEF_H
# define PUSH_SWAP_TYPEDEF_H

typedef struct s_lst
{
	int				key;
	int				val;
	struct s_lst	*prev;
	struct s_lst	*next;
}	t_lst;

typedef struct s_node
{
	int	key;
	int	size;
	int	lst;
	int	pos;
	int	fixed;
}	t_node;

#endif
