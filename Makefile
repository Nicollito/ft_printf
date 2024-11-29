.PHONY: all re clean fclean libft

NAME = libftprintf.a
CC = cc 
FLAGS = -Wall -Werror -Wextra
SRC =    ft_printf.c
OBJ = $(SRC:.c=.o)

all : $(NAME) libft

%.o : %.c ft_printf.h Makefile libft/libft.h 
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ) -libft

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

libft:
	$(MAKE) -C libft

re : clean all