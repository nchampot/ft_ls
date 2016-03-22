SRC = opt_l.c main.c recursive.c parse_args.c

OBJ = $(SRC:.c=.o)

LIB = libft/

NAME = ft_ls

CC = clang

all : $(NAME)

$(NAME): $(OBJ)
	 @echo Libft compilation ...
	 @make -C $(LIB)
	 @echo Generating ft_ls
	 @$(CC) $(OBJ) $(LIB)libft.a -o $(NAME) -Wall -Wextra

re : fclean all

clean :
	@rm -f $(OBJ)

fclean : clean
	 @rm -f $(NAME)
