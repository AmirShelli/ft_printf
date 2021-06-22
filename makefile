LIBFT = libft.a

NAME = ft_printf.a

SRCS =  ft_printf.c

OBJS = $(SRCS:.c=.o)

CC = gcc -c -Wall -Wextra -Werror

# INCLUDES = -I./includes

all : $(NAME)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	$(CC) $(FLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	$(clean)
	rm -rf $(NAME)

re : fclean all