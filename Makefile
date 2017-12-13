NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

DIR_C = SRCS

DIR_O = temp

HEADER = -I Includes

SOURCES =	ft_printf.c \
			ft_attribuate.c

SRCS = $(addprefix ./SRCS/,$(SRC:.c=.o))

OBJ = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

# PROGRESS BAR
T = $(words $(addprefix ./SRCS/,$(SRC)))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C '*' 100 / $T`%]"

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
	@echo "\n$(NAME) edited"

$(DIR_O)/%.o: $(DIR_C)/%.c
	@mkdir -p temp
	@printf "%-60b\r" "$(ECHO) Compressing $@"
	@$(CC) $(HEADER) -o $@ -c $<

clean:
	@make -C ./libft/ clean
	@rm -f $(OBJ)
	@rm -rf $(DIR_O)
	@echo "clean	: done"

fclean:	clean
	@make -C ./libft/ fclean
	@rm -f $(NAME)
	@echo "fclean	: done"

re: fclean all

go: all
	@gcc -o ft_printf main.c $(NAME)
	@time ./ft_printf

.PHONY: all re fclean clean
