# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/15 14:57:28 by ataguiro          #+#    #+#              #
#    Updated: 2018/04/09 18:56:16 by ataguiro         ###   ########.fr        #
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
SRCDIR	:=	src/
SRCDIR1	:=	src_nm/
SRCDIR2	:=	src_otool/
OBJDIR	:=	obj/
INCDIR	:=	include/
LIBDIR	:=	libft/
SRC		:=	$(SRCDIR)$(SRCDIR1)nm.c \
			$(SRCDIR)$(SRCDIR1)main_nm.c \
			$(SRCDIR)$(SRCDIR1)handle_macho64.c \
			$(SRCDIR)$(SRCDIR1)handle_macho32.c \
			$(SRCDIR)$(SRCDIR1)handle_fat64.c \
			$(SRCDIR)$(SRCDIR1)handle_fat32.c \
			$(SRCDIR)$(SRCDIR1)handle_ar.c \
			$(SRCDIR)$(SRCDIR1)clear_globals.c \
			$(SRCDIR)$(SRCDIR1)swap_bytes.c \
			$(SRCDIR)$(SRCDIR1)sort.c \
			$(SRCDIR)$(SRCDIR1)check.c
SRC2	:=	$(SRCDIR)$(SRCDIR2)otool.c \
			$(SRCDIR)$(SRCDIR2)main_otool.c \
			$(SRCDIR)$(SRCDIR2)handle_macho64o.c \
			$(SRCDIR)$(SRCDIR2)handle_macho32o.c \
			$(SRCDIR)$(SRCDIR1)clear_globals.c \
			$(SRCDIR)$(SRCDIR2)handle_ar.c \
			$(SRCDIR)$(SRCDIR1)check.c \
			$(SRCDIR)$(SRCDIR2)handle_fat64.c \
			$(SRCDIR)$(SRCDIR2)handle_fat32.c \
			$(SRCDIR)$(SRCDIR1)swap_bytes.c


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
	rm -rf $(EXTRA).dSYM

$(OBJDIR)%.o: $(SRCDIR)%.c $(CACHEF)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	printf "\r"
	printf $(BGREEN)"[ compiling objects... ] "
	printf "$(shell echo 'scale=2;$(INDEX)/18 * 100' | bc)%%"$(EOC)
	$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

$(CACHEF):
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	test -d $(OBJDIR)src_nm || mkdir $(OBJDIR)src_nm
	test -d $(OBJDIR)src_otool || mkdir $(OBJDIR)src_otool
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
