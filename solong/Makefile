NAME = so_long

NAME_BONUS = so_long_bonus

CC	= gcc

HEADERS:= -I ./includes 

#CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3 $(HEADERS)
CFLAGS = -Wall -Werror -Wextra -g3 $(HEADERS)
#valgrind --leak-check=full --show-leak-kinds=all
#CFLAGS = -Wall -Werror -Wextra $(HEADERS) 

MLX_FLAGS = -lXext -lX11 -lm -lbsd

GPATH = mlx_linux

MLX_PATH = $(GPATH)/libmlx.a

MF = Makefile

# Colors
RED =			\033[0;31m
GREEN =			\033[0;92m
CYAN =			\033[0;96m
BLUE=			\033[0;34m
PURPLE=			\033[0;95m
YELLOW =		\033[0;93m
RESET=			\033[0m

SRCS :=	 $(addprefix sources/, \
	core/main.c	core/map.c	core/init.c	core/hook.c	core/movement.c	core/utils.c\
	parsing/parsing_map.c	parsing/parsing_utils.c parsing/parsing_init.c)

SRCS_BONUS :=	 $(addprefix sources_bonus/, \
	core/main.c	core/map.c	core/init.c	core/hook.c	core/movement.c	core/utils.c	core/animations.c\
	parsing/parsing_map.c	parsing/parsing_utils.c parsing/parsing_init.c)

SRCS_LIB := $(addprefix ./libft/, \
	ft_strnstr.c	get_next_line_utils.c	get_next_line.c	strlen_no_tab.c	ft_strncmp.c	ft_itoa.c\
	ft_printf.c	ft_putchar.c	ft_puthexadecimal.c	ft_putnbr.c\
	ft_putpadress.c	ft_putstr.c	ft_putunbr.c)

OBJS = $(SRCS:.c=.o) $(SRCS_LIB:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o) $(SRCS_LIB:.c=.o)

$(NAME) :  print_title $(MF) _mlx $(OBJS) $(MLX_PATH)
	@echo "$(GREEN)Creando ejecutable"
	$(CC) $(CFLAGS) $(OBJS) $(MLX_PATH) $(MLX_FLAGS) -o $(NAME)
	@echo "Ejecutable Creado$(RESET)"


$(NAME_BONUS) :  print_title $(MF) _mlx $(OBJS_BONUS) $(MLX_PATH)
	@echo "$(GREEN)Creando ejecutable"
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLX_PATH) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "Ejecutable Creado$(RESET)"


all : print_title _mlx $(NAME)

bonus : print_title _mlx $(NAME_BONUS)

print_title:
	echo "$(RED)  ██████  ▒█████      ██▓     ▒█████   ███▄    █   ▄████  "
	echo "▒██    ▒ ▒██▒  ██▒   ▓██▒    ▒██▒  ██▒ ██ ▀█   █  ██▒ ▀█▒ "
	echo "░ ▓██▄   ▒██░  ██▒   ▒██░    ▒██░  ██▒▓██  ▀█ ██▒▒██░▄▄▄░ "
	echo "  ▒   ██▒▒██   ██░   ▒██░    ▒██   ██░▓██▒  ▐▌██▒░▓█  ██▓ "
	echo "▒██████▒▒░ ████▓▒░   ░██████▒░ ████▓▒░▒██░   ▓██░░▒▓███▀▒ "
	echo "▒ ▒▓▒ ▒ ░░ ▒░▒░▒░    ░ ▒░▓  ░░ ▒░▒░▒░ ░ ▒░   ▒ ▒  ░▒   ▒  "
	echo "░ ░▒  ░ ░  ░ ▒ ▒░    ░ ░ ▒  ░  ░ ▒ ▒░ ░ ░░   ░ ▒░  ░   ░  "
	echo "░  ░  ░  ░ ░ ░ ▒       ░ ░   ░ ░ ░ ▒     ░   ░ ░ ░ ░   ░  "
	echo "      ░      ░ ░         ░  ░    ░ ░           ░       ░   $(RESET) $(PURPLE)"


#	echo "                                                      "
#	echo "          %                                           "
#	echo "          +**%                                        "
#	echo "          #+*%%****                        %          "
#	echo "           *%=%%%**+-===::::-*%         *:=*          "
#	echo "           *%%*+****+***+***+***+:*#:=**==###         "
#	echo "           +%%**=+***+*++**+***+=+*++*++*%%#          "
#	echo "          **%%%#**+*+*********++**+**=*%%%%#          "
#	echo "          +%%%%%#**+**********+****==#%%%%%*          "
#	echo "         %*%%%%%#************+****++%%%**%**          "
#	echo "         ##%%%%%%***#%%%%%#******=*=**#%%**%          "
#	echo "       #-=%%%%%%%%%%%%%%%%************%%%%##          "
#	echo "     +...:+#%%%%%%%%%%%%%%**##********#%%#%+#         "
#	echo "     =.......:=*%%%%%%%%%%%%#*=----==++:..*%%#%       "
#	echo "     *...:..........::................*%%%%%+%%*      "
#	echo "      =....:..:..:..:................#%%%%%%%%#*      "
#	echo "       *:.........+%%:...............*%%%%%%%%%%%     "
#	echo "       *%%=:..:-+%%%%%*:............+**%%%%%%%%%*%    "
#	echo "       +%%%*#%%%%**##+*%#===:..:=*%%%%%*#%%%%%%%%*    "
#	echo "       *%%%%%:*%%%%=%%%%%%%%%%%%%%%%%%%-#**%%%%%%%#   "
#	echo "      #%%%%%%%%*=%#*+%%%%%%%%%%%%%*==#%%**%%%%%%%%%%  "
#	echo "     +%%%%%%%%%%%%=*#*+#*+++=+**%%%%%%%#=%%%%%%%%%%*  "
#	echo "    *%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%+%%%%%%%%%%%*  "
#	echo "   *%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*#%%%%%%%%%%%%  "
#	echo "  +%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#+%%%%%%%%%%%%%% "
#	echo " *%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*+%%%%%%%%%%%%%* "
#	echo "*#%%%%%%%%%%%%%###*****#######%%%%%##==***+*+**+++=+*#"
#	echo "                                                      "
#	echo "                                                       $(RESET) $(CYAN)"


	echo "  :@*            #@#         "       
	echo "  @-.##       :@*  @.        "       
	echo " :@    +. #@@@#    @-        "       
	echo " -@                #=        "       
	echo " -@                =*        "       
	echo " :@                 %        "       
	echo " .@   %@@.   -@@=   @        "       
	echo "  @                =*        "       
	echo " :@                @         "       
	echo " -@                +*        "       
	echo " -@                 :@-      "       
	echo " -@                   #@     "       
	echo " -@                    *%    "       
	echo " .@:                    *@   "       
	echo "  @+                     @=  "       
	echo "  =#   -%@@+             :@  "       
	echo "    :@*.   =%             %: "       
	echo "   +%     .%=             +# "       
	echo "  :@     @+               =% "       
	echo "  #+    **                +# "       
	echo "  **     =@#++.           %: "       
	echo "   @.                    %*  "       
	echo "    @*                .%@.   "       
	echo "      .#@@@@@@@@@@@@@+       $(RESET) $(CYAN)"       




clean :
	rm -fr $(OBJS) $(OBJS_BONUS)
	@make clean -C $(GPATH)

fclean : clean
	rm -f  $(NAME) $(NAME_BONUS)
	@make clean -C $(GPATH)

re : fclean all

re_b : fclean bonus

_mlx :
	@echo "$(GREEN)Creando ejecutable de MiniLibX"
	@make -C $(GPATH)


.PHONY: all clean fclean re bonus re_b
.SILENT: print_title