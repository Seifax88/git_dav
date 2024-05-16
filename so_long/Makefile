NAME = so_long

CC	= gcc

HEADERS:= -I ./includes 

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3 $(HEADERS) 
# CFLAGS = -Wall -Werror -Wextra $(HEADERS) 

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
	core/main.c	core/map.c	core/init.c	\
	parsing/parsing_map.c	parsing/parsing_utils.c parsing/parsing_init.c)

SRCS_LIB := $(addprefix ./libft/, \
	ft_strnstr.c	get_next_line_utils.c	get_next_line.c	strlen_no_tab.c)

OBJS = $(SRCS:.c=.o) $(SRCS_LIB:.c=.o)

$(NAME) :  print_title $(MF) _mlx $(OBJS) $(MLX_PATH)
	@echo "$(GREEN)Creando ejecutable"
	$(CC) $(CFLAGS) $(OBJS) $(MLX_PATH) $(MLX_FLAGS) -o $(NAME)
	@echo "Ejecutable Creado$(RESET)"



all : print_title _mlx $(NAME)

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
	rm -fr $(OBJS)
	@make clean -C $(GPATH)

fclean : clean
	rm -f  $(NAME)
	@make clean -C $(GPATH)

re : fclean all

_mlx :
	@echo "$(GREEN)Creando ejecutable de MiniLibX"
	@make -C $(GPATH)


.PHONY: all clean fclean re
.SILENT: print_title