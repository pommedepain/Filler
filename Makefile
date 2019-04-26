# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 17:20:13 by psentilh          #+#    #+#              #
#    Updated: 2019/04/26 14:02:18 by psentilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	psentilh.filler
NAME_VW		=	viewer

CC			=	gcc
DEBUG		=	no
ifeq ($(DEBUG), yes)
	CFLAGS= -Wall -Werror -Wextra -fsanitize=address -g3 -I$(INC_PATH)
else
	CFLAGS= -Wall -Werror -Wextra -g3 -I$(INC_PATH)
endif


SRC_PATH	= 	./src/
SRC_FILLER	=	filler/main.c\
				filler/parsing.c\
				filler/utils.c\
				filler/solve.c\
				filler/piece.c\
				filler/board.c

SRC_VIEWER	=	viewer/viewer.c\
				viewer/parsing.c\

SRC_ALL		=	filler/main.c\
				filler/parsing.c\
				filler/utils.c\
				filler/solve.c\
				filler/piece.c\
				filler/board.c\
				viewer/viewer.c\
				viewer/parsing.c\

SRCS_ALL	=	$(addprefix $(SRC_PATH), $(SRC_ALL))
SRCS_F		=	$(addprefix $(SRC_PATH), $(SRC_FILLER))
SRCS_V		=	$(addprefix $(SRC_PATH), $(SRC_VIEWER))


OBJ_PATH	=	./obj/
OBJ_F		=	$(SRC_FILLER:.c=.o)
OBJ_V		=	$(SRC_VIEWER:.c=.o)
OBJ_ALL		=	$(SRC_ALL:.c=.o)

OBJS_F		=	$(addprefix $(OBJ_PATH), $(OBJ_F))
OBJS_V		=	$(addprefix $(OBJ_PATH), $(OBJ_V))
OBJS_ALL	=	$(addprefix $(OBJ_PATH), $(OBJ_ALL))


INC_PATH 	=	./inc/
INCS		=	$(addprefix $(INC_PATH), $(INC))
INC			=	filler.h



all: 			$(NAME) $(NAME_VW)
ifeq ($(DEBUG), yes)
	@echo "\033[7;33m*** DEBUG MODE ACTIVATED ***\033[0m"
endif

$(NAME): 		$(OBJ_PATH) $(OBJS_ALL)
				@cd libft; make all
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_F) -L libft/ -lft
				@echo "\033[1;31m>>> $(NAME) is ready to FIGHT ! 🤜 💢 🤛  <<<\033[0m"

$(NAME_VW):		$(OBJ_PATH) $(OBJS_ALL)
				@$(CC) $(CFLAGS) -o $(NAME_VW) $(OBJS_V) -L libft/ -lft -lncurses
				@echo "\033[1;35m>>> The $(NAME_VW)'s ready to blow your mind ! 👤 💥  <<<\033[0m"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c $(INCS)
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "\033[36m[Compiling] :	$<...\033[0m"

$(OBJ_PATH):
				@mkdir -p $(OBJ_PATH)
				@mkdir -p $(OBJ_PATH)/filler
				@mkdir -p $(OBJ_PATH)/viewer

clean:
				@make clean -C libft/
				@/bin/rm -rf $(OBJ_PATH)
				@echo "\033[35m[Cleaning] :	$(OBJ_PATH)...\033[0m"

fclean:			clean
				@make fclean -C libft/
				@/bin/rm -rf $(NAME)
				@echo "\033[32m[Cleaning] :	$(NAME)...\033[0m"
				@/bin/rm -rf $(NAME_VW)
				@echo "\033[32m[Cleaning] :	$(NAME_VW)...\033[0m"

re: 			fclean all

norme:
				@printf "\e[31m"
				@norminette $(SRCS_ALL) | grep -Eiw -B1 "Warning|Error" || true
				@printf "\n"
				@norminette $(INC_PATH) | grep -Eiw -B1 "Warning|Error" || true
				@printf "\e[0m\n"

.PHONY: 		all clean fclean re norme
