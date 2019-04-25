# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 17:20:13 by psentilh          #+#    #+#              #
#    Updated: 2019/04/25 16:58:59 by psentilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = psentilh.filler
NAME_VW = viewer

CC = gcc
DEBUG= no
ifeq ($(DEBUG), yes)
	CFLAGS= -Wall -Werror -Wextra -fsanitize=address -g3 -I$(INC_DIR)
else
	CFLAGS= -Wall -Werror -Wextra -g3 -I$(INC_DIR)
endif


SRC_DIR = 		./src/
SRC_FILLER =	filler/main.c\
				filler/parsing.c\
				filler/utils.c\
				filler/solve.c\
				filler/piece.c\
				filler/board.c

SRC_VIEWER =	viewer/viewer.c

SRC_ALL =		filler/main.c\
				filler/parsing.c\
				filler/utils.c\
				filler/solve.c\
				filler/piece.c\
				filler/board.c\
				viewer/viewer.c\

SRCS_F =	$(addprefix $(SRC_DIR), $(SRC_FILLER))
SRCS_V =	$(addprefix $(SRC_DIR), $(SRC_VIEWER))


OBJ_DIR=	./obj/
OBJ_F =		$(SRC_FILLER:.c=.o)
OBJ_V =		$(SRC_VIEWER:.c=.o)
OBJ_ALL =	$(SRC_ALL:.c=.o)
OBJS_F =	$(addprefix $(OBJ_DIR), $(OBJ_FILLER))
OBJS_V =	$(addprefix $(OBJ_DIR), $(OBJ_VIEWER))
OBJS_ALL =	$(addprefix $(OBJ_DIR), $(OBJ_ALL))

INC_DIR =	./inc/
INCS =		$(addprefix $(INC_DIR), $(INC))
INC =		filler.h

all: 		filler viewer
ifeq ($(DEBUG), yes)
	@echo "\033[7;33m*** DEBUG MODE ACTIVATED ***\033[0m"
endif

filler: 	$(OBJ_DIR) $(OBJS_ALL)
			@make -C libft/
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_F) -L libft/ -lft
			@echo "\033[1;31m>>> $(NAME) is ready to FIGHT ! 🤜 💢 🤛  <<<\033[0m"

viewer:		$(OBJ_DIR) $(OBJS_ALL)
			@make -C libft/
			@$(CC) $(CFLAGS) -o $(NAME_VW) $(OBJS_V) -L libft/ -lft -lncurses
			@echo "\033[7;35m>>>  The $(NAME_VW)'s ready to blow your mind ! 👤 💥  <<<\033[0m"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INCS)
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "\033[36m[Compiling] :	$<...\033[0m"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(OBJ_DIR)/filler
				@mkdir -p $(OBJ_DIR)/viewer

clean:
	@make clean -C libft/
	@/bin/rm -rf $(OBJ_DIR)
	@echo "\033[35m[Cleaning] :	$(OBJ_DIR)...\033[0m"

fclean: clean
	@make fclean -C libft/
	@/bin/rm -rf $(NAME)
	@echo "\033[32m[Cleaning] :	$(NAME)...\033[0m"
	@/bin/rm -rf $(NAME_VW)
	@echo "\033[32m[Cleaning] :	$(NAME_VW)...\033[0m"

re: fclean all

norme:
	@printf "\e[31m"
	@norminette $(SRCS) | grep -Eiw -B1 "Warning|Error" || true
	@printf "\n"
	@norminette $(SRCS_V) | grep -Eiw -B1 "Warning|Error" || true
	@printf "\n"
	@norminette $(INC_DIR) | grep -Eiw -B1 "Warning|Error" || true
	@printf "\e[0m\n"

.PHONY: all clean fclean re norme
