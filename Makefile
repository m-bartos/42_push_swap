# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 10:59:06 by mbartos           #+#    #+#              #
#    Updated: 2024/01/15 11:39:36 by mbartos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD =	\033[1m
GREEN =	\033[32m
RED =	\033[31m
BCYAN =	\033[96m
NC =	\033[0m

#name
NAME =		push_swap

#compiler
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror

#libft
LIBFT_PATH =	./lib/libft/
LIBFT_NAME =	libft.a
LIBFT =			$(LIBFT_PATH)$(LIBFT_NAME)

#Includes
INC_LIBFT =		-I ./libft

#sources
SRC_PATH =	src/
SRC = 	push_swap.c \
		array_utils.c \
		do_operations.c \
		errors.c \
		ft_stck.c \
		ft_stck_utils.c \
		get_numof_opers_utils.c \
		get_numof_opers.c \
		pa_pb.c \
		possblts_init_cpy.c \
		ra_rb.c \
		rra_rrb.c \
		sa_sb.c \
		sort_two_three_nums.c \
		turk_algo.c
SRCS =	$(addprefix $(SRC_PATH), $(SRC))

#objects
OBJ_PATH =	obj/
OBJ =		$(SRC:.c=.o)
OBJS =		$(addprefix $(OBJ_PATH), $(OBJ))

all: libft $(NAME)

$(OBJ_PATH)%.o :$(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC_LIBFT)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

libft:
	@echo "$(BOLD)$(BCYAN)[ Making libft... ]$(NC)"
	@make -sC $(LIBFT_PATH)
	@echo "$(BOLD)$(GREEN)[ Libft ready! ]$(NC)"

$(NAME): $(OBJS)
	@echo "$(BOLD)$(BCYAN)[ Compiling $(NAME)... ]$(NC)"
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(BOLD)$(GREEN)[ $(NAME) ready! ]$(NC)"

clean:
	@rm -Rf $(OBJ_PATH)
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)
	@echo "$(BOLD)$(RED)[ Obj files deleted ]$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BOLD)$(RED)[ Program deleted ]$(NC)"

re: fclean all

.PHONY: all, re, clean, fclean, libft