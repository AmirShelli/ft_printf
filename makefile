LIBFT = ./libft/libft.a

NAME = ft_printf.a

SRCS =  $(wildcard ./src/*.c)

OBJS = $(SRCS:.c=.o)

INCLUDES = -I./includes

CC = gcc -c -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) all -C ./libft
	cp $(LIBFT) $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

clean :
	rm -rf $(wildcard ./*.o)
	rm -rf $(wildcard ./*/*.o)

fclean : clean
	$(clean)
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all