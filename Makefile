# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 16:12:24 by dlavaury          #+#    #+#              #
#    Updated: 2017/12/21 20:43:17 by dlavaury         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

DIR_C = SRCS

DIR_O = temp

HEADER = -I Includes

SOURCES =	ft_printf.c \
			ft_init_printf.c \
			ft_attribuate.c \
			ft_flags_parser.c \
			ft_star_gestion.c \
			ft_precision_parser.c \
			ft_len_mod_parser.c \
			ft_put_type.c \
			ft_set_car.c \
			ft_set_string.c \
			ft_putbin.c \
			ft_no_types.c \
			ft_filler.c \
			ft_buffering.c

SRCS = $(addprefix ./SRCS/,$(SOURCES))

OBJ = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

# PROGRESS BAR
T = $(words $($(SOURCES)))
N = 0
C = $(words $N)$(eval N := x $N)
@ECHO = "[`expr $C '*' 100 / $T`%]"

#Color
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ) $?
	@ranlib $(NAME)
	@echo "\n$(_CYAN)$(NAME)$(_END) $(_GREEN)edited$(_END)"

$(DIR_O)/%.o: $(DIR_C)/%.c
	@mkdir -p temp
	@printf "%-60b\r" "$(ECHO) Compressing $@"
	@$(CC) $(HEADER) -o $@ -c $<

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rm -rf $(DIR_O)
	@echo "$(_RED)clean$(_END)	: $(_GREEN)done$(_END)"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "$(_RED)fclean$(_END)	: $(_GREEN)done$(_END)"

re: fclean
	@make all

go:
	@make -j4
	@gcc -o ft_printf main.c $(NAME)
	@time ./ft_printf

norminette:
	@norminette **/**.[ch]

.PHONY: all re fclean clean
