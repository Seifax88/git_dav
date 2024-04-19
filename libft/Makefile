NAME = libft.a

CC	= gcc

CFLAGS = -Wall -Werror -Wextra

OBJ_DIR = obj

OBJ_DIR_BONUS = obj_bonus

SRCS :=	ft_atoi.c	ft_isascii.c	ft_memcmp.c	ft_putendl_fd.c	ft_strdup.c	ft_strlen.c	ft_strtrim.c	ft_bzero.c	\
	ft_isdigit.c	ft_memcpy.c	ft_putnbr_fd.c	ft_striteri.c	ft_strmapi.c	ft_substr.c	ft_calloc.c	ft_isprint.c	\
	ft_memmove.c	ft_putstr_fd.c	ft_strjoin.c	ft_strncmp.c	ft_tolower.c	ft_isalnum.c	ft_itoa.c	\
	ft_memset.c	ft_split.c	ft_strlcat.c	ft_strnstr.c	ft_toupper.c	ft_isalpha.c	ft_memchr.c	ft_putchar_fd.c	\
	ft_strchr.c	ft_strlcpy.c	ft_strrchr.c

SRCS_BONUS :=	ft_lstnew_bonus.c	ft_lstadd_front_bonus.c	ft_lstsize_bonus.c	ft_lstlast_bonus.c	ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	\
	ft_lstclear_bonus.c	ft_lstiter_bonus.c	ft_lstmap_bonus.c

OBJS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

OBJS_BONUS := $(patsubst %.c, $(OBJ_DIR_BONUS)/%.o, $(SRCS_BONUS))

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR_BONUS):
	mkdir -p $(OBJ_DIR_BONUS)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR_BONUS)/%.o: %.c | $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus : $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

all : $(NAME)

clean :
	rm -fr $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean : clean
	rm -f  $(NAME)

re : fclean all

.PHONY: bonus all clean fclean re