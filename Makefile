# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 17:20:13 by psentilh          #+#    #+#              #
#    Updated: 2019/04/11 16:48:09 by psentilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = psentilh.filler

CC = gcc
DEBUG= yes
ifeq ($(DEBUG), yes)
	CFLAGS= -Wall -Werror -Wextra -fsanitize=address -g3 -I$(INC_DIR)
else
	CFLAGS= -Wall -Werror -Wextra -g3 -I$(INC_DIR)
endif

SRC_DIR = ./src_filler/
SRCS = $(addprefix $(SRC_DIR), $(SRC))
SRC =	main.c\
		parsing.c\

OBJ_DIR = ./obj_filler/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ = $(SRC:.c=.o)

INC_DIR = ./inc/
INCS = $(addprefix $(INC_DIR), $(INC))
INC = filler.h

all: $(NAME)
ifeq ($(DEBUG), yes)
	@echo "\033[7;33m*** DEBUG MODE ACTIVATED ***\033[0m"
endif

$(NAME): $(OBJ_DIR) $(OBJS)
	@cd libft; make all
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft/ -lft
	@echo "\033[1;31m>>> $(NAME) is ready to FIGHT ! 🤜 💥 🤛  <<<\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[36m[Compiling] :	$<...\033[0m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@cd libft; make clean
	@/bin/rm -rf $(OBJS)
	@/bin/rm -rf $(OBJ_DIR)
	@echo "\033[35m[Cleaning] :	$(OBJ_DIR)...\033[0m"

fclean: clean
	@cd libft; make fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[32m[Cleaning] :	$(NAME)...\033[0m"

re: fclean all

norme:
	@printf "\e[31m"
	@norminette $(SRCS) | grep -Eiw -B1 "Warning|Error" || true
	@printf "\n"
	@norminette $(INC_DIR) | grep -Eiw -B1 "Warning|Error" || true
	@printf "\e[0m\n"

.PHONY: all clean fclean re norme
