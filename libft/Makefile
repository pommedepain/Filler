# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:28:41 by psentilh          #+#    #+#              #
#    Updated: 2019/04/09 18:48:59 by psentilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)

SRC_DIR = ./src/
SRCS = $(addprefix $(SRC_DIR), $(SRC))
SRC =	ft_lltoa_base.c\
		ft_ulltoa_base.c\
		ft_numlen.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strdup.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_word_count.c\
		ft_tab_filling.c\
		ft_itoa.c\
		ft_digit_len.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		get_next_line.c\
		ft_print_words_tables.c\
		ft_tabdel.c\
		ft_strlens.c\
		ft_strjoinfs1.c\
		ft_strjoinfs2.c\
		ft_strjoinfs1s2.c\
		ft_strjoins.c\
		ft_strdups.c\
		ft_strcmps.c\
		ft_strchrs.c\
		ft_str_dupfree.c\
		ft_no_whitespaces.c\
		ft_convert_base.c\
		ft_strcountsplit.c\
		ft_strtrimc.c\
		ft_strclen.c\
		ft_tabcpy.c\
		ft_strccpy.c\
		ft_strndup.c\
		ft_strnlen.c\
		ft_chrchar.c\
		ft_chrstring.c\
		pf_arg_c.c\
		pf_arg_s.c\
		pf_arg_p.c\
		pf_arg_d.c\
		pf_arg_dd.c\
		pf_arg_o.c\
		pf_arg_oo.c\
		pf_arg_u.c\
		pf_arg_uu.c\
		pf_arg_x.c\
		pf_arg_b.c\
		pf_arg_xx.c\
		pf_arg_per.c\
		pf_arg_z.c\
		pf_manage_struct.c\
		pf_split_float.c\
		pf_float_utils.c\
		pf_atoull.c\
		pf_double.c\
		pf_arg_f.c\
		pf_conversion_util.c\
		pf_conversion.c\
		ft_printf.c\
		pf_parsing_util.c\
		pf_arg_manager.c\
		pf_str_manager.c\
		pf_util.c\
		pf_util_2.c\
		pf_new_functions.c\
		

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ = $(SRC:.c=.o)

INC_DIR = ../inc/
INCS = $(addprefix $(INC_DIR), $(INC))
INC = libft.h

all: $(NAME)

$(NAME): $(MSSG) $(OBJ_DIR) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[32m>>> $(NAME) is ready to use ! ✅  <<<\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[36m[Compiling] :	$<...\033[0m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJS)
	@rm -rf obj/
	@echo "\033[35m[Cleaning] :	$(OBJ_DIR)...\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32m[Cleaning] :	$(NAME)...\033[0m"

re: fclean all
