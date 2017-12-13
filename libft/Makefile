GCC = gcc

CFLAGS = -Wall -Wextra -Werror -I ./Includes/

NAME	= libft.a

SRC = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_isprint.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c\
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_isupper.c \
		ft_islower.c \
		ft_countnumber.c \
		ft_putnbrendl.c \
		ft_countwords.c \
		ft_printstrsplit_tab.c \
		ft_strsplit_lst.c \
		ft_putlst.c \
		ft_lstcount.c \
		ft_fileaddone.c \
		ft_filedelone.c \
		ft_pileaddone.c \
		ft_filedelone.c \
		ft_strsplit_file.c \
		ft_strsplit_pile.c \
		ft_str_is_printable.c \
		ft_str_is_uppercase.c \
		ft_str_is_numeric.c \
		ft_str_is_alpha.c \
		ft_strcapitalize.c \
		ft_strlowercase.c \
		ft_str_is_lowercase.c \
		ft_strupcase.c \
		ft_swap.c \
		get_next_line.c

OBJ = $(addprefix ./SRCS/,$(SRC:.c=.o))

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
	@ar rc $(NAME) $?
	@ranlib $(NAME)
	@echo "\n$(NAME) edited"

%.o: %.c
	@printf "%-60b\r" "$(ECHO) Compressing $@"
	@$(GCC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ)
	@rm -f libft.h.gch
#	@echo "$(_YELLOW)clean$(_END)	: $(_GREEN)done$(_END)"

fclean:	clean
	@rm -f $(NAME)
#	@echo "$(_YELLOW)fclean$(_END)	: $(_GREEN)done$(_END)"

re: fclean all

.PHONY: all re fclean clean
