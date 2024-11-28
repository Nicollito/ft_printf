.PHONY : all clean fclean re

NAME = libftprintf.a

CC = cc

CFLAGS = -Werror -Wextra -Wall

SRCS =	ft_printf.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS) libft.a
	
clean : 
	rm -rf $(OBJS)
	rm -rf $(BOBJS)

fclean : 
	$(MAKE) clean
	rm -rf $(NAME)
	rm -rf .bonus

re : 
	$(MAKE) fclean 
	$(MAKE) all
