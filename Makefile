# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#              #
#    Updated: 2024/03/12 19:16:08 by ykosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME		= push_swap
BONUS		= checker

# Enumeration of files
SRCM		= pswp_sort.c pswp_sort_le6.c pswp_sort_gt6.c \
			  pswp_nodeinit.c pswp_nodeclear.c pswp_nodeseek.c pswp_nodeupd.c \
			  pswp_nodenew_a.c pswp_nodenew_b.c pswp_nodenew_set.c \
			  pswp_sort_three.c pswp_sort_three_a.c pswp_sort_three_b.c \
			  pswp_div_a_whole.c pswp_div_a_top.c pswp_div_a_bottom.c \
			  pswp_div_b_whole.c pswp_div_b_top.c pswp_div_b_bottom.c \
			  pswp_sortchk_three.c pswp_sortchk_range.c pswp_sortchk_co.c \
			  pswp_cmp.c pswp_cmp_dawt.c \
			  pswp_calc_pivot.c pswp_calc_size.c  pswp_calc_bias.c \
			  pswp_search_max.c pswp_search_min.c \
			  pswp_search_le.c pswp_search_gt.c  pswp_search_range.c \
			  pswp_print_oper.c \
			  ft_lstsize.c ft_swap.c ft_hasflag.c
SRCC		= pswp_main.c pswp_arg2arr.c pswp_argchk.c pswp_stackinit.c \
			  pswp_oper_px.c pswp_oper_sx.c pswp_oper_rx.c pswp_oper_rrx.c \
			  pswp_sortchk.c pswp_print_err.c \
			  pswp_lstnew.c pswp_lstadd_next.c pswp_lstclear.c \
			  ft_lstclear.c ft_split.c ft_putstr.c ft_atoi.c \
			  ft_strncmp.c ft_strlen.c ft_inrange.c
SRCB		= pswp_sort_bonus.c pswp_sort_input.c pswp_print_oper_bonus.c \
  			  get_next_line.c get_next_line_utils.c
SRCD		= debug_pswp.c debug_common.c

# Enumeration of directories
SRCDIR		= ./src
INCDIR		= ./include
OBJDIR		= ./obj

# Aliases of commands
CC			= cc
RM			= rm

# Command options (flags)
CFLAGS		= -MMD -Wall -Wextra -Werror
DEBUGFLAGS	= -g -ggdb -fsanitize=address \
			  -fno-omit-frame-pointer
ifneq ($(shell uname -s), Darwin)
	DEBUGFLAGS	+= -fstack-usage
endif
INCLUDES	= -I$(INCDIR)
RMFLAGS		= -rf

# Macros to replace and/or integrate #1
SRCS		= $(addprefix $(SRCDIR)/, $(SRCM)) \
			  $(addprefix $(SRCDIR)/, $(SRCC))

# Redefination when the specific target
ifeq ($(MAKECMDGOALS), bonus)
	DEF		+= -D BONUS=1
	CFLAGS	+= $(DEBUGFLAGS)
	DEF		+= -D DEBUG_MODE=1
	NAME	= $(BONUS)
	SRCS	= $(addprefix $(SRCDIR)/, $(SRCB)) \
			  $(addprefix $(SRCDIR)/, $(SRCC)) \
			  $(addprefix $(SRCDIR)/, $(SRCD))
endif
ifeq ($(MAKECMDGOALS), debug)
	CFLAGS	+= $(DEBUGFLAGS)
	DEF		+= -D DEBUG_MODE=1
endif

# Macros to replace and/or integrate #2
OBJS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.d)))

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all clean fclean re

# Mandatory targets
all: $(NAME)
clean:
	$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	$(RM) $(RMFLAGS) $(NAME) $(BONUS)
re: fclean $(OBJDIR) all

# Additional targets
debug: $(NAME)
bonus: $(BONUS)

# Recipes
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<

# Including and ignore .dep files when they are not found
-include $(DEPS)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
