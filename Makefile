# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/15 14:57:28 by ataguiro          #+#    #+#              #
#    Updated: 2018/03/29 18:45:10 by ataguiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Editable =====
NAME	:=	ft_nm
EXTRA	:=	ft_otool
INDEX	:=	1
# ====================

# ===== Standard =====
CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -g -fsanitize=address
SRCDIR	:=	src_nm/
SRCDIR2	:=	src_otool/
OBJDIR	:=	obj/
INCDIR	:=	include/
LIBDIR	:=	libft/
SRC		:=	$(SRCDIR)nm.c \
			$(SRCDIR)main_nm.c \
			$(SRCDIR)handle_macho64.c \
			$(SRCDIR)handle_macho32.c \
			$(SRCDIR)handle_fat64.c \
			$(SRCDIR)handle_fat32.c \
			$(SRCDIR)handle_ar.c \
			$(SRCDIR)clear_globals.c \
			$(SRCDIR)swap_bytes.c \
			$(SRCDIR)sort.c \
			$(SRCDIR)check.c
SRC2	:=	$(SRCDIR2)otool.c \
			$(SRCDIR2)main_otool.c \
			$(SRCDIR2)handle_macho64o.c \
			$(SRCDIR2)handle_macho32o.c \
			$(SRCDIR)clear_globals.c \
			$(SRCDIR)handle_ar.c \
			$(SRCDIR)check.c \
			$(SRCDIR2)handle_fat64.c \
			$(SRCDIR2)handle_fat32.c \
			$(SRCDIR)swap_bytes.c


OBJ		:=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o) $(SRC2:$(SRCDIR)%.c=$(OBJDIR)%.o)
OBJ1	:=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
OBJ2	:=	$(SRC2:$(SRCDIR)%.c=$(OBJDIR)%.o)
INC		:=	-I./$(INCDIR) -I./$(LIBDIR)$(INCDIR)
LIBPATH	:=	-L./$(LIBDIR) -lft
CACHEF	:=	.cache_exists
# ====================

# ====== Colors ======
CLEAR		= "\033[2K"
UP			= "\033[A"
EOC			= "\033[0;0m"
BLACK		= "\033[0;30m"
RED			= "\033[0;31m"
BRED		= "\033[1;31m"
GREEN		= "\033[0;32m"
BGREEN		= "\033[1;32m"
YELLOW		= "\033[0;33m"
BLUE		= "\033[0;34m"
PURPLE		= "\033[0;35m"
CYAN		= "\033[0;36m"
WHITE		= "\033[0;37m"
# ====================

.PHONY: all libft norme clean fclean re
.SILENT:

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ1) -o $@ $(LIBPATH) $(LIB) $(INC)
	echo "\033[1;32m" "\n✓ $@ ok ;)" "\033[0m"
	$(CC) $(CFLAGS)  $(OBJ2) -o $(EXTRA) $(LIBPATH) $(LIB) $(INC)
	echo "\033[1;32m" "\n✓ $(EXTRA) ok ;)" "\033[0m"

$(OBJDIR)%.o: $(SRCDIR)%.c $(CACHEF)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	printf "\r"
	printf $(BGREEN)"[ compiling objects... ] "
	printf "$(shell echo 'scale=2;$(INDEX)/26 * 100' | bc)%%"$(EOC)
	$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

$(CACHEF):
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	test -d $(CACHEF) || touch $(CACHEF)

%.c:
	printf $(RED)"Missing file : $@\n"$(EOC)

libft:
	make -C $(LIBDIR)

norme:
	norminette $(SRCDIR) $(INCDIR) | grep -v Norme -B1 || true
	norminette $(LIBFT)$(SRCDIR) $(LIBFT)$(INCDIR) | grep -v Norme -B1 || true

clean:
	make -C $(LIBDIR) clean
	rm -rf $(OBJDIR) $(CACHEF)
	printf $(YELLOW)"All objects removed\n"$(EOC)

fclean: clean
	make -C $(LIBDIR) fclean
	rm -f $(NAME)
	rm -rf $(EXTRA) $(EXTRA).dSYM
	printf $(RED)"$(NAME) removed\n"$(EOC)

re: fclean all
