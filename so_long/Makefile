NAME = solong

CC	= gcc

HEADERS:= -I ./includes

CFLAGS = -Wall -Werror -Wextra $(HEADERS)

SRCS :=	 $(addprefix sources/, \
	core/main.c	core/map.c)

SRCS_LIB := $(addprefix ./libft/, \
	ft_strnstr.c	get_next_line_utils.c	get_next_line.c)

OBJS = $(SRCS:.c=.o) $(SRCS_LIB:.c=.o)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	rm -fr $(OBJS)

fclean : clean
	rm -f  $(NAME)

re : fclean all

.PHONY: all clean fclean re