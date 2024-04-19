NAME = libftprintf.a

CC	= gcc

CFLAGS = -Wall -Werror -Wextra

OBJ_DIR = obj

SRCS :=	ft_printf.c	ft_putchar.c	ft_putstr.c	ft_putnbr.c	ft_putunbr.c	ft_puthexadecimal.c	ft_putpadress.c	ft_strlen.c

OBJS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

all : $(NAME)

clean :
	rm -fr $(OBJ_DIR)

fclean : clean
	rm -f  $(NAME)

re : fclean all

.PHONY: all clean fclean re