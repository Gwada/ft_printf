# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 09:48:57 by dlavaury          #+#    #+#              #
#    Updated: 2018/01/13 16:39:50 by dlavaury         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

GCC = gcc

FLAGS = -Wall -Wextra -Werror

HARDFLAGS = -Weverything

HEADER = -I Includes

SOURCES =	tools.c \
			attribuate.c \
			strchr.c \
			ft_printf.c \
			ft_dprintf.c \
			ft_sprintf.c \
			parsing.c \
			set_car.c \
			set_string.c \
			set_nbr.c \
			set_float.c \
			set_len.c \
			set_bin.c \
			set_colors.c \
			set_adress.c \
			ft_no_types.c \
			ft_filler.c \
			ft_buffering.c

OBJ = $(addprefix SRCS/,$(SOURCES:.c=.o))

# PROGRESS BAR
T = $(words $(addprefix SRCS/,$(SOURCES)))
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
	@ar rc $(NAME) $?
	@ranlib $(NAME)
	@echo "\n$(_CYAN)$(NAME)$(_END) $(_GREEN)edited$(_END)"

%.o: %.c
	@printf "%-60b\r" "$(ECHO)Compressing $@"
	@$(GCC) $(FLAGS) $(HEADER) -o $@ -c $<

clean:
	@rm -f **/**.o
	@echo "$(_RED)clean$(_END)	: $(_GREEN)done$(_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(_RED)fclean$(_END)	: $(_GREEN)done$(_END)"

re: fclean
	@make all

go:
	@clear
	@make -j3 re
	@$(GCC) $(HARDFLAGS) -o ft_printf main.c $(NAME)
	@./ft_printf

.PHONY: all re fclean clean
