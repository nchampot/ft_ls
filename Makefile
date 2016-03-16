SRC = main.c recurcive.c init.c parse_args.c

OBJ = $(SRC:.c=.o)

NAME = ft_ls

CC = clang

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) libft/libft.a -o $(NAME) -Wall -Wextra

re : fclean all

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)
