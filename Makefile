.PHONY: all re clean fclean libft

NAME = libftprintf.a
CC = cc 
FLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)
LIB = libft/*.o

all : $(NAME) libft

%.o : %.c 
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(LIB)
	ar -rcs $(NAME) $(LIB) $(OBJ)

$(LIB) : libft
	@true

libft :
	$(MAKE) -C libft

clean : 
	rm -f $(OBJ)

fclean :
	$(MAKE) clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re : clean all