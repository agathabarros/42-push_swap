# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/17 12:11:09 by agathabarro       #+#    #+#              #
#    Updated: 2023/09/28 16:48:29 by agathabarro      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FIRST STEPS
CC = cc -g
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
GDB = gdb
VAL = valgrind --leak-check=full --track-origin=yes

#colors
RESET   := \033[0m
GREEN   := \033[32m
CYAN    := \033[1;36m
YELLOW  := \033[33m
BLUE    := \033[34m
WHITE   := \033[0m
RED     := \033[1;31m
BOLD    := \033[1m
# PUSH_SWAP

NAME = push_swap.a
SRCS =	./lib_functions/ft_atoi.c \
        ./lib_functions/ft_lstadd_back.c \
        ./lib_functions/ft_lstlast.c \
        ./lib_functions/ft_lstnew.c \
        ./lib_functions/ft_lstsize.c \
		./lib_functions/ft_isdigit.c \
        ./operations/push.c \
        ./operations/reverse.c \
        ./operations/rotate.c \
        ./operations/swap.c \
        ./utils/erro.c \
        ./utils/utils.c \
        ./utils/check.c \
		./push_swap.c

OBJSDIR = objects
OBJS = $(addprefix $(OBJSDIR)/,$(SRCS:.c=.o))

# MAKE RULES

all: $(NAME) push_swap

$(NAME): $(OBJS)
	@echo "$(GREEN)$(BOLD)Creating objects directory...$(RESET)"
	ar -rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)Objects created!$(RESET)"
	
$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

push_swap: $(PUSH_SWAP_OBJ) $(NAME)
	@echo "$(GREEN)$(BOLD)Creating executable...$(RESET)"
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(NAME) -o push_swap
	@echo "$(GREEN)$(BOLD)Executable created!$(RESET)"

clean:
	@echo "$(YELLOW)$(BOLD)Removing objects...$(RESET)"
	$(RM) $(OBJSDIR)
	@echo "$(YELLOW)$(BOLD)Objects removed!$(RESET)"

fclean: clean
	@echo "$(RED)$(BOLD)Removing executable...$(RESET)"
	$(RM) push_swap push_swap.a
	@echo "$(RED)$(BOLD)Executable removed!$(RESET)"

re: fclean all
	@echo "$(GREEN)$(BOLD)Recompiled successfully!$(RESET)"

.SILENT: