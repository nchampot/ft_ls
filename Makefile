SRC = func.c opt_l.c main.c recursive.c parse_args.c errors.c t_sort.c get_stat.c l_sort.c opt_l_tools.c free_2d.c

OBJ = $(SRC:.c=.o)

LIB = libft/

NAME = ft_ls

CC = clang

all : $(NAME)

$(NAME): $(OBJ)
	 @echo Libft compilation ...
	 @make -C $(LIB)
	 @echo Generating ft_ls
	 @$(CC) $(OBJ) $(LIB)libft.a -o $(NAME) -Wall -Wextra -Werror

re : fclean all

clean :
	@rm -f $(OBJ)
	@make clean -C $(LIB)

fclean : clean
	 @rm -f $(NAME)
	 @make fclean -C $(LIB)
