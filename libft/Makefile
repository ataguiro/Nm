# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:52:41 by ataguiro          #+#    #+#              #
#    Updated: 2018/03/07 12:11:39 by ataguiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
INDEX = 1
CFLAGS = -c -Wall -Wextra -Werror

SRC_PATH = ./src/
SRC_NAME =	ft_printf.c \
			parsing.c \
			types.c \
			sin_printf.c \
			tl_focuscpy.c \
			tl_isinstr.c \
			tl_ntoa.c \
			tl_ntoa_8.c \
			tl_ntoa_16.c \
			tl_ntoa_2.c \
			tl_ntoa_u.c \
			tl_strnlen.c \
			tl_wstrnlen.c \
			type_c.c \
			type_o.c \
			type_p.c \
			type_cup.c \
			type_s.c \
			type_sup.c \
			type_u.c \
			type_x.c \
			type_d.c \
			type_b.c \
			fill_wchar_c.c \
			fill_wchar_s.c \
			ft_datodi.c \
			ft_isinstr.c \
			ft_itabremove.c \
			ft_readline.c \
			btree_del.c \
			ft_count_words.c \
			ft_lstdel.c \
			ft_itoa.c \
			ft_ctoa.c \
			ft_foreach.c \
			ft_getlast.c \
			ft_lstpushback.c \
			ft_rand.c \
			ft_range.c \
			ft_strrev.c \
			ft_swap.c \
			ft_swap_str.c \
			ft_tabdup.c \
			ft_tabremove.c \
			ft_tabstr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_isdigit.c \
			ft_memdel.c \
			ft_strclr.c \
			ft_strnew.c \
			ft_isprint.c \
			ft_memmove.c \
			ft_strcmp.c \
			ft_strnstr.c \
			ft_isspace.c \
			ft_memset.c \
			ft_strcpy.c \
			ft_strrchr.c \
			btree_create_node.c \
			ft_intlength.c \
			ft_strdel.c \
			btree_insert_data.c \
			ft_strsplit.c \
			ft_putchar.c \
			ft_strdup.c \
			ft_strstr.c \
			ft_putchar_fd.c \
			ft_strequ.c \
			ft_strsub.c \
			ft_putendl.c \
			ft_strtrim.c \
			ft_atoi.c \
			ft_lstadd.c \
			ft_striter.c \
			ft_putendl_fd.c \
			ft_striteri.c \
			ft_bzero.c \
			ft_putnbr.c \
			ft_strjoin.c \
			ft_tabdel.c \
			ft_lstdelone.c \
			ft_tablen.c \
			ft_lstiter.c \
			ft_putnbr_fd.c \
			ft_strlcat.c \
			ft_lstsize.c \
			ft_putstr.c \
			ft_strlen.c \
			ft_lstmap.c \
			ft_strmap.c \
			ft_tolower.c \
			ft_lstnew.c \
			ft_putstr_fd.c \
			ft_strmapi.c \
			ft_toupper.c \
			ft_memalloc.c \
			ft_strncat.c \
			ft_memccpy.c \
			ft_strncmp.c \
			ft_isalnum.c \
			ft_memchr.c \
			ft_strcat.c \
			ft_strncpy.c \
			get_next_line.c \
			ft_isalpha.c \
			ft_memcmp.c \
			ft_isascii.c \
			ft_memcpy.c \
			ft_strchr.c \
			ft_strnequ.c
SRC = $(addprefix $(SRC_PATH), $(SCR_NAME))
OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INCLUDE_PATH = -I ./include/

.PHONY: clean fclean re all

all : $(NAME)

$(NAME): $(OBJ) $(SRC)
	@echo "\033[1;32m" "\n✓ Libft done" "\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(INCLUDE_PATH) $(CFLAGS) -c $< -o $@
	@printf "\r"
	@printf "\033[1;32m[ compiling Libft... ] "
	@printf "$(shell echo 'scale=2;$(INDEX)/108 * 100' | bc)%%\033[0m"
	$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
