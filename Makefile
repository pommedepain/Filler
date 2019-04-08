# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 17:20:13 by psentilh          #+#    #+#              #
#    Updated: 2019/04/08 17:28:13 by psentilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = psentilh.filler

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)

SRC_DIR = ./src/
SRCS = $(addprefix $(SRC_DIR), $(SRC))
SRC =

OBJ_DIR = ./obj_filler/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ = $(SRC:.c=.o)

INC_DIR = ./inc/
INCS = $(addprefix $(INC_DIR), $(INC))
INC = filler.h

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@cd libft; make all
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[31m\033[1mCreating $(NAME)...\033[0m"
	@echo "\033[32m\033[1m$(NAME) all done and ready to go ! 🤗 \033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[36mCompiling $<...\033[0m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@cd libft; make clean
	@/bin/rm -rf $(OBJS)
	@/bin/rm -rf obj/
	@echo "\033[35mCleaning $(OBJ_DIR)...\033[0m"

fclean: clean
	@cd libft; make fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[32mCleaning $(NAME)...\033[0m"

re: fclean all
