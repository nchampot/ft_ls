SRC = main.c recurcive.c init.c parse_args.c

OBJ = $(SRC:.c=.o)

LIB = libft

NAME = ft_ls

CC = clang

all : $(NAME)

$(NAME): $(OBJ)
	make re -C $(LIB)
	$(CC) $(OBJ) $(LIB)/libft.a -o $(NAME) -Wall -Wextra

re : fclean all

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)
