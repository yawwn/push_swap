# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 19:50:11 by mcathery          #+#    #+#              #
#    Updated: 2020/08/13 14:14:26 by mcathery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = checker
NAME_PS = push_swap

FILES = b_addit_functions.c b_display.c c_check_function.c c_operations.c \
				 p_best_move_finder.c p_global_sort.c p_operations.c p_operations2.c \
				 p_rotation.c p_sort_3_and_5_elements.c p_sort_algorithms.c c_parse.c p_parse.c

FILES_C = c_checker.c
FILES_PS = p_push_swap.c

LFTDIR = ./libft/
LIBFT = $(LFTDIR)libft.a

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

SRC_PATH = src/
O_PATH = obj/
HEADER = -I./incl/ -I$(LFTDIR)
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lft -L$(LFTDIR)

SRC = $(addprefix $(SRC_PATH), $(FILES))
SRC_C = $(addprefix $(SRC_PATH), $(FILES_C))
SRC_PS = $(addprefix $(SRC_PATH), $(FILES_PS))

OBJ =$(addprefix $(O_PATH),$(subst .c,.o,$(FILES)))
OBJ_C =$(addprefix $(O_PATH),$(subst .c,.o,$(FILES_C)))
OBJ_PS =$(addprefix $(O_PATH),$(subst .c,.o,$(FILES_PS)))

CHECK_O = .o_path_exists

all: $(NAME_C) $(NAME_PS)

$(NAME_C): $(LIBFT) $(OBJ) $(OBJ_C)
	@echo $(CYAN) " - Compiling $@" $(EOC)
	@gcc $(CFLAGS) $(SRC) $(LFLAGS) $(SRC_C) -o $(NAME_C)
	@echo $(GREEN) " - OK" $(GREEN)

$(NAME_PS): $(LIBFT) $(OBJ) $(OBJ_PS)
	@echo $(CYAN) " - Compiling $@" $(EOC)
	@gcc $(CFLAGS) $(SRC) $(LFLAGS) $(SRC_PS) -o $(NAME_PS)
	@echo $(GREEN) " - OK" $(GREEN)

$(LIBFT):
	@make -C $(LFTDIR)

$(O_PATH)%.o: $(SRC_PATH)%.c | $(CHECK_O)
	@echo $(PURPLE) " - Compiling $< into $@" $(GREEN)
	@gcc $(CFLAGS) $(HEADER) -c $< -o $@

$(CHECK_O):
	@mkdir $(O_PATH)
	@touch $(CHECK_O)

clean:
	@echo $(RED) " - Removing object files" $(EOC)
	@rm -rf $(O_PATH)
	@rm -rf $(CHECK_O)
	@cd $(LFTDIR) && make clean

fclean: clean
	@echo $(RED) " - Removing $(NAME_C)" $(EOC)
	@rm -rf $(NAME_C)
	@echo $(RED) " - Removing $(NAME_PS)" $(EOC)
	@rm -rf $(NAME_PS)
	@cd $(LFTDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re